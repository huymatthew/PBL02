#include <Dialogs/AddBillDiag.h>
#include <iostream>
#include <QMessageBox>
using namespace std;

AddBillDialog::AddBillDialog(QWidget *parent, DataManager *dataManager) : QDialog(parent), dataManager(dataManager) {
    setupUi(this);
    setFixedSize(400, 300);
    roomComboBox->addItems(dataManager->roomM.getRoomListForComboBox(2));
}

AddBillDialog::~AddBillDialog() {}

void AddBillDialog::on_saveButton_clicked() {
    // Implement save logic here
    QMessageBox::information(this, "Save", "Save button clicked!");
    accept();
}

void AddBillDialog::on_cancelButton_clicked() {
    reject();
}

void AddBillDialog::setRoom(int roomId) {
    Contract* contract = dataManager->contractM.getActiveContractByRoom(roomId);
    if (contract) {
        contractID->setText(QString::number(contract->getContractId()));
        Room* room = dataManager->roomM.getRoom(roomId);
        if (room) {
            roomComboBox->setCurrentText(QString::fromStdString(room->getRoomName()));
        }
        Tenant* tenant = dataManager->getMainTenantFromContract(contract->getContractId());
        if (tenant) {
            resName->setText(QString::fromStdString(tenant->getFullName()));
        }
        monthlyRentSpinBox->setValue(contract->getMonthlyRent());
        roomComboBox->setCurrentIndex(roomId - 1);
        monthComboBox->setCurrentIndex(QDate::currentDate().month() - 1);
        yearEdit->setText(QString::number(QDate::currentDate().year()));
    } else {
        QMessageBox::warning(this, "No Active Contract", "The selected room does not have an active contract.");
    }
}
