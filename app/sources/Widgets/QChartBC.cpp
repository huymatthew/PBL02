#include <Widgets/QChartBC.h>
#include <Manager/DataManager.h>
#include <Core/ExtraFormat.h>

#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QValueAxis>
#include <iostream>

using namespace QtCharts;

QChartBC::QChartBC(QChartView* chartView) : chartView(chartView) {}

QChartBC::~QChartBC() {}

#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChart>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QStringList>
#include <QDate>
#include <iostream>
#include <QtMath>

void QChartBC::updateChart(QDate startMonth, QDate endMonth) {
    QBarSeries* series = new QBarSeries();

    QBarSet* setPaid = new QBarSet("Đã thanh toán");
    QBarSet* setUnpaid = new QBarSet("Chưa thanh toán");

    QChart* chart = new QChart();
    QStringList categories;

    double maxPaidRevenue = 0.0;
    double maxUnpaidRevenue = 0.0;

    QDate currentMonth = startMonth;
    while (currentMonth <= endMonth) {
        QString monthYearStr = currentMonth.toString("yyyy-MM");
        
        categories << currentMonth.toString("MM-yy"); 

        double paidRevenue = DataManager::getInstance().getBillManager().getTotalPaidBillInDay(monthYearStr);
        if (paidRevenue > maxPaidRevenue) {
            maxPaidRevenue = paidRevenue;
        }
        *setPaid << (paidRevenue / 1000000.0);

        double unpaidRevenue = DataManager::getInstance().getBillManager().getTotalUnpaidBillInDay(monthYearStr);
        if (unpaidRevenue > maxUnpaidRevenue) {
            maxUnpaidRevenue = unpaidRevenue;
        }
        *setUnpaid << (unpaidRevenue / 1000000.0);
        currentMonth = currentMonth.addMonths(1);
    }

    series->append(setPaid);
    series->append(setUnpaid);
    
    chart->addSeries(series);
    chart->setTitle("Biểu Đồ Doanh Thu (Đã trả / Chưa trả)");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis* axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis* axisY = new QValueAxis();
    
    double highestRevenue = qMax(maxPaidRevenue, maxUnpaidRevenue);
    
    double axisMax = qCeil(highestRevenue / 1000000.0);

    if (axisMax == 0) {
        axisMax = 1.0;
    }

    axisY->setLabelFormat("%.1f");
    axisY->setTitleText("Doanh Thu (triệu VND)");
    axisY->setMin(0); 
    axisY->setMax(axisMax);
    
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chartView->setChart(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
}
