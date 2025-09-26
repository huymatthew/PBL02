#include <Dialogs/AddRoomDiag.h>
#include <QDialogButtonBox>
#include <QMessageBox>
#include <iostream>

using namespace std;

AddRoomDiag::AddRoomDiag(QWidget* parent, RoomManager& roomManager)
    : QDialog(parent), roomManager(roomManager) {
    setupUi(this);
    signalConnect();
}

AddRoomDiag::~AddRoomDiag() {}

void AddRoomDiag::on_buttonBox_accepted() {
    string roomName = lineEditRoomNumber->text().toStdString();
    int contractId = 0;
    int roomType = comboBoxRoomType->currentIndex();
    double monthlyRent = doubleSpinBoxRentPrice->value();
    string description = plainTextEditDescription->toPlainText().toStdString();
    int status = comboBoxStatus->currentIndex();

    if (roomName.empty()){
        QMessageBox::warning(this, "Input Error", "Room Number is required.");
        return;
    }
    roomManager.addRoom(roomName, contractId, roomType, monthlyRent, " " + description, status);
    accept();
}

void AddRoomDiag::on_buttonBox_rejected() {
    // Handle the rejection of the dialog
    reject();
}

void AddRoomDiag::signalConnect() {
    connect(buttonBox, &QDialogButtonBox::accepted, this, &AddRoomDiag::on_buttonBox_accepted);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &AddRoomDiag::on_buttonBox_rejected);
}
