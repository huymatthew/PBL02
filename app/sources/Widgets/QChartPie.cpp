#include <Widgets/QChartPie.h>
#include <Manager/DataManager.h>
#include <Core/ExtraFormat.h>

#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QDateTime>
#include <iostream>
#include <set>

using namespace QtCharts;

QChartPie::QChartPie(QChartView* chartView) : chartView(chartView) {}

QChartPie::~QChartPie() {}

void QChartPie::updateChart(QDate startDate, QDate endDate) {
    DataManager& dm = DataManager::getInstance();
    RoomManager& roomM = dm.getRoomManager();
    ContractManager& contractM = dm.getContractManager();

    // Tổng số phòng
    int totalRooms = roomM.getCount();
    
    // Đếm số phòng có hợp đồng active (status = 1) trong khoảng thời gian
    std::set<int> occupiedRoomIds;
    
    // Duyệt qua tất cả hợp đồng
    for (const auto& contract : contractM.items) {
        // Chỉ xét hợp đồng đang active (status = 1: còn hiệu lực)
        // status = 0: hết hiệu lực, status = 2: vô hiệu hóa
        if (contract.getStatus() != 1) {
            continue;
        }
        
        QDate contractStart = QDate::fromString(QString::fromStdString(contract.getStartDate()), "yyyy-MM-dd");
        QDate contractEnd = QDate::fromString(QString::fromStdString(contract.getEndDate()), "yyyy-MM-dd");
        
        // Kiểm tra xem hợp đồng có giao với khoảng thời gian [startDate, endDate] không
        // Hai khoảng [a1, a2] và [b1, b2] giao nhau khi: !(a2 < b1 || a1 > b2)
        bool overlaps = !(contractEnd < startDate || contractStart > endDate);
        
        if (overlaps) {
            occupiedRoomIds.insert(contract.getRoomId());
        }
    }
    
    int occupiedCount = occupiedRoomIds.size();
    int emptyCount = totalRooms - occupiedCount;
    
    // Tính phần trăm
    double occupiedPercent = totalRooms > 0 ? (occupiedCount * 100.0 / totalRooms) : 0.0;
    double emptyPercent = totalRooms > 0 ? (emptyCount * 100.0 / totalRooms) : 0.0;
    
    // Tạo pie series
    QPieSeries* series = new QPieSeries();
    
    QPieSlice* occupiedSlice = series->append(QString("Đã thuê (%1 phòng)").arg(occupiedCount), occupiedCount);
    occupiedSlice->setBrush(QColor("#4CAF50")); // Green
    occupiedSlice->setLabelVisible(true);
    occupiedSlice->setLabel(QString("Đã thuê\n%1 phòng (%2%)")
                            .arg(occupiedCount)
                            .arg(occupiedPercent, 0, 'f', 1));
    
    QPieSlice* emptySlice = series->append(QString("Trống (%1 phòng)").arg(emptyCount), emptyCount);
    emptySlice->setBrush(QColor("#F44336")); // Red
    emptySlice->setLabelVisible(true);
    emptySlice->setLabel(QString("Trống\n%1 phòng (%2%)")
                         .arg(emptyCount)
                         .arg(emptyPercent, 0, 'f', 1));
    
    // Tạo chart
    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(QString("Tỉ Lệ Lấp Đầy Phòng\n(%1 đến %2)")
                   .arg(startDate.toString("dd/MM/yyyy"))
                   .arg(endDate.toString("dd/MM/yyyy")));
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    
    // Highlight khi hover
    for (QPieSlice* slice : series->slices()) {
        QObject::connect(slice, &QPieSlice::hovered, [slice](bool show) {
            slice->setExploded(show);
            slice->setLabelVisible(show);
        });
    }
    
    chartView->setChart(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
}
