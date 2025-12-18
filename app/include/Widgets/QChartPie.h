#ifndef QCHARTPIE_H
#define QCHARTPIE_H

#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QLegend>

using namespace QtCharts;

class QChartPie {
    QChartView* chartView;
public:
    QChartPie(QChartView* chartView);
    ~QChartPie();

    void updateChart(QDate startDate, QDate endDate);
};

#endif // QCHARTPIE_H
