#ifndef MODEL_VIEW_HELPER_H
#define MODEL_VIEW_HELPER_H

#include <QStandardItemModel>
#include <QTableView>
#include <QHeaderView>
#include <QAbstractItemView>
#include <QSortFilterProxyModel>
#include <QString>

class ModelViewHelper {
public:
    // Configure table view with common settings
    static void configureTableView(QTableView* tableView);
    
    // Create a sortable/filterable proxy model
    static QSortFilterProxyModel* createProxyModel(QStandardItemModel* sourceModel, QObject* parent = nullptr);
    
    // Apply search filter to proxy model
    static void applySearchFilter(QSortFilterProxyModel* proxyModel, const QString& searchText, int column = -1);
    
    // Safely replace model and delete old one
    static void replaceModel(QTableView* tableView, QStandardItemModel* newModel);
    
    // Auto-resize columns with minimum width
    static void autoResizeColumns(QTableView* tableView, int minWidth = 100);
    
    // Set column widths as percentages of total width
    static void setColumnPercentWidths(QTableView* tableView, const QList<double>& percentages);
    
    // Export model data to CSV
    static bool exportToCSV(QStandardItemModel* model, const QString& filename);
    
    // Get selected row data
    static QStringList getSelectedRowData(QTableView* tableView);
    
    // Highlight row by value in specific column
    static void highlightRowByValue(QTableView* tableView, const QString& value, int column = 0);

private:
    ModelViewHelper() = default; // Static class, no instantiation
};

#endif // MODEL_VIEW_HELPER_H
