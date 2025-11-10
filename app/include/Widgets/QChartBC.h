#ifndef QCHARTBC_H
#define QCHARTBC_H

#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QLegend>

using namespace QtCharts;

class QChartBC{
    QChartView* chartView;
public:
    QChartBC(QChartView* chartView);
    ~QChartBC();

    void updateChart(QDate startDate, QDate endDate);
};

#endif // QCHARTBC_H