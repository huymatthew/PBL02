#include <Dialogs/SearchFilterDiag.h>

SearchFilterDialog::SearchFilterDialog(QWidget* parent) : QDialog(parent), Ui_SearchFilterDialog() {
    setupUi(this);
    signalConnect();
}
SearchFilterDialog::~SearchFilterDialog() {
        
}

void SearchFilterDialog::on_buttonBox_accepted() {
    cout << "Accepted: Push Search/Filter Data" << endl;
}

void SearchFilterDialog::on_buttonBox_rejected() {
    cout << "Rejected" << endl;
    reject();
}

void SearchFilterDialog::signalConnect() {
    connect(buttonBox, &QDialogButtonBox::accepted, this, &SearchFilterDialog::on_buttonBox_accepted);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &SearchFilterDialog::on_buttonBox_rejected);
}