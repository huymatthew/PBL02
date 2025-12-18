#ifndef SEARCH_FILTER_DIAG_H
#define SEARCH_FILTER_DIAG_H

#include <QDialog>
#include <QTableView>

#include <Manager/DataManager.h>
#include <search_filter_dialog.h>

using namespace std;
class SearchFilterDialog : public QDialog, public Ui_SearchFilterDialog {
    QTableView* view;
    bool shouldShowIt(int rowIndex);
public:
    SearchFilterDialog(QWidget* parent, QTableView* view, int searchMode = -1);
    ~SearchFilterDialog();

    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void signalConnect();


    void applySearchFilter();
};
#endif // SEARCH_FILTER_DIAG_H