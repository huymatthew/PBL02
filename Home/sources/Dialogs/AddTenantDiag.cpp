#include <Dialogs/AddTenantDiag.h>
#include <iostream>

using namespace std;

AddTenantDiag::AddTenantDiag(QWidget *parent, TenantManager& tenantManager) : QDialog(parent), Ui_AddTenantDialog(), tenantManager(tenantManager) {
    setupUi(this);
    signalConnect();
}

AddTenantDiag::~AddTenantDiag() {
}

void AddTenantDiag::on_buttonBox_accepted() {
    cout << "Accepted: Push Tenant Data" << endl;
    string fullName = lineEditFullName->text().toStdString();
    string phone = lineEditPhone->text().toStdString();
    string identityCard = lineEditCCCD->text().toStdString();
    string dateOfBirth = formatDate(dateEditBirthDate->text());
    int contractId = 0;
    bool isMainTenant = false;

    if (fullName.empty() || phone.empty() || identityCard.empty() || dateOfBirth.empty()) {
        cerr << "Error: All fields must be filled." << endl;
        return;
    }

    tenantManager.addTenant(fullName, phone, identityCard, dateOfBirth, contractId, isMainTenant);
    accept();
}

void AddTenantDiag::on_buttonBox_rejected() {
    cout << "Rejected" << endl;
    reject();
}

void AddTenantDiag::signalConnect() {
    connect(buttonBox, &QDialogButtonBox::accepted, this, &AddTenantDiag::on_buttonBox_accepted);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &AddTenantDiag::on_buttonBox_rejected);
}
