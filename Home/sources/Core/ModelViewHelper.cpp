#include <Core/ModelViewHelper.h>
#include <QApplication>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QBrush>
#include <QColor>

void ModelViewHelper::configureTableView(QTableView* tableView) {
    if (!tableView) return;
    
    // Enable sorting
    tableView->setSortingEnabled(true);
    
    // Set selection behavior
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    
    // Set alternating row colors
    tableView->setAlternatingRowColors(true);
    
    // Resize columns to content
    tableView->resizeColumnsToContents();
    
    // Auto-resize with minimum width
    autoResizeColumns(tableView, 100);
    
    // Set horizontal header properties
    tableView->horizontalHeader()->setStretchLastSection(true);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    
    // Show grid
    tableView->setShowGrid(true);
    
    // Set horizontal scroll mode
    tableView->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    tableView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
}

QSortFilterProxyModel* ModelViewHelper::createProxyModel(QStandardItemModel* sourceModel, QObject* parent) {
    if (!sourceModel) return nullptr;
    
    QSortFilterProxyModel* proxyModel = new QSortFilterProxyModel(parent);
    proxyModel->setSourceModel(sourceModel);
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxyModel->setFilterKeyColumn(-1); // Search all columns
    
    return proxyModel;
}

void ModelViewHelper::applySearchFilter(QSortFilterProxyModel* proxyModel, const QString& searchText, int column) {
    if (!proxyModel) return;
    
    proxyModel->setFilterKeyColumn(column);
    proxyModel->setFilterRegExp(QRegExp(searchText, Qt::CaseInsensitive, QRegExp::FixedString));
}

void ModelViewHelper::replaceModel(QTableView* tableView, QStandardItemModel* newModel) {
    if (!tableView) return;
    
    // Get old model and delete it
    QAbstractItemModel* oldModel = tableView->model();
    if (oldModel && oldModel != newModel) {
        delete oldModel;
    }
    
    // Set new model
    tableView->setModel(newModel);
    
    // Configure the view
    configureTableView(tableView);
}

void ModelViewHelper::autoResizeColumns(QTableView* tableView, int minWidth) {
    if (!tableView || !tableView->model()) return;
    
    tableView->resizeColumnsToContents();
    
    // Ensure minimum width
    for (int i = 0; i < tableView->model()->columnCount(); ++i) {
        if (tableView->columnWidth(i) < minWidth) {
            tableView->setColumnWidth(i, minWidth);
        }
    }
}

void ModelViewHelper::setColumnPercentWidths(QTableView* tableView, const QList<double>& percentages) {
    if (!tableView || !tableView->model() || percentages.size() != tableView->model()->columnCount()) {
        return;
    }
    
    int totalWidth = tableView->viewport()->width();
    
    for (int i = 0; i < percentages.size(); ++i) {
        int columnWidth = static_cast<int>(totalWidth * percentages[i] / 100.0);
        tableView->setColumnWidth(i, columnWidth);
    }
}

bool ModelViewHelper::exportToCSV(QStandardItemModel* model, const QString& filename) {
    if (!model) return false;
    
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return false;
    }
    
    QTextStream stream(&file);
    
    // Write headers
    QStringList headers;
    for (int col = 0; col < model->columnCount(); ++col) {
        headers << model->headerData(col, Qt::Horizontal).toString();
    }
    stream << headers.join(",") << "\n";
    
    // Write data
    for (int row = 0; row < model->rowCount(); ++row) {
        QStringList rowData;
        for (int col = 0; col < model->columnCount(); ++col) {
            QModelIndex index = model->index(row, col);
            QString data = model->data(index).toString();
            // Escape commas and quotes in CSV
            if (data.contains(",") || data.contains("\"")) {
                data = "\"" + data.replace("\"", "\"\"") + "\"";
            }
            rowData << data;
        }
        stream << rowData.join(",") << "\n";
    }
    
    return true;
}

QStringList ModelViewHelper::getSelectedRowData(QTableView* tableView) {
    QStringList rowData;
    if (!tableView || !tableView->model()) return rowData;
    
    QModelIndexList selection = tableView->selectionModel()->selectedRows();
    if (selection.isEmpty()) return rowData;
    
    int row = selection.first().row();
    for (int col = 0; col < tableView->model()->columnCount(); ++col) {
        QModelIndex index = tableView->model()->index(row, col);
        rowData << tableView->model()->data(index).toString();
    }
    
    return rowData;
}

void ModelViewHelper::highlightRowByValue(QTableView* tableView, const QString& value, int column) {
    if (!tableView || !tableView->model()) return;
    
    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(tableView->model());
    if (!model) return;
    
    for (int row = 0; row < model->rowCount(); ++row) {
        QModelIndex index = model->index(row, column);
        if (model->data(index).toString() == value) {
            // Highlight the entire row
            for (int col = 0; col < model->columnCount(); ++col) {
                QStandardItem* item = model->item(row, col);
                if (item) {
                    item->setBackground(QBrush(QColor(255, 255, 0, 100))); // Light yellow
                }
            }
            
            // Scroll to the row
            tableView->scrollTo(index);
            break;
        }
    }
}
