#include <Dialogs/AddTenantDiag.h>
#include <Core/ExtraFormat.h>
#include <iostream>

using namespace std;

AddTenantDiag::AddTenantDiag(QWidget *parent) : QDialog(parent), Ui_AddTenantDialog() {
    setupUi(this);
    signalConnect();
}

AddTenantDiag::AddTenantDiag(Tenant* tenant, QWidget* parent) : QDialog(parent), Ui_AddTenantDialog(), editingTenant(tenant) {
    setupUi(this);
    signalConnect();

    if (editingTenant != nullptr) {
        lineEditFullName->setText(QString::fromStdString(editingTenant->getFullName()));
        lineEditPhone->setText(QString::fromStdString(editingTenant->getPhone()));
        lineEditCCCD->setText(QString::fromStdString(editingTenant->getIdentityCard()));
        dateEditBirthDate->setDate(QDate::fromString(QString::fromStdString(editingTenant->getDateOfBirth()), "yyyy-MM-dd"));
        comboBoxGender->setCurrentIndex(editingTenant->getGender());
    }
}

AddTenantDiag::~AddTenantDiag() {
        
}

void AddTenantDiag::on_buttonBox_accepted() {
    cout << "Accepted: Push Tenant Data" << endl;
    string fullName = lineEditFullName->text().toStdString();
    string phone = lineEditPhone->text().toStdString();
    string identityCard = lineEditCCCD->text().toStdString();
    string dateOfBirth = formatDate(dateEditBirthDate->text());
    int gender = comboBoxGender->currentIndex();

    if (fullName.empty() || phone.empty() || identityCard.empty() || dateOfBirth.empty()) {
        cerr << "Error: All fields must be filled." << endl;
        return;
    }
    fullName = formatName(fullName);

    if (editingTenant != nullptr) {
        Tenant newTenant(editingTenant->getId(), fullName, phone, identityCard, dateOfBirth, gender);
        DataManager::getInstance().getTenantManager().update(editingTenant->getId(), newTenant);
    }
    else {
        DataManager::getInstance().getTenantManager().addTenant(fullName, phone, identityCard, dateOfBirth, gender);
    }
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
