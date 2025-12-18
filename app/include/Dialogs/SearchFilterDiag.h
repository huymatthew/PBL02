#ifndef SEARCH_FILTER_DIAG_H
#define SEARCH_FILTER_DIAG_H

#include <QDialog>

#include <Manager/DataManager.h>
#include <search_filter_dialog.h>

using namespace std;
class SearchFilterDialog : public QDialog, public Ui_SearchFilterDialog {
public:
    SearchFilterDialog(QWidget* parent);
    ~SearchFilterDialog();

    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void signalConnect();

private:
    int editingIndex = -1;
};
#endif // SEARCH_FILTER_DIAG_H