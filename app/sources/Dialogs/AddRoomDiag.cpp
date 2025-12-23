#include <Dialogs/AddRoomDiag.h>
#include <QDialogButtonBox>
#include <QMessageBox>
#include <iostream>

using namespace std;

AddRoomDiag::AddRoomDiag(QWidget* parent) : QDialog(parent), Ui_AddRoomDialog() {
    setupUi(this);
    signalConnect();
}

AddRoomDiag::AddRoomDiag(Room* room, QWidget* parent) : QDialog(parent), Ui_AddRoomDialog(), editingRoom(room) {
    setupUi(this);
    signalConnect();

    if (editingRoom != nullptr) {
        lineEditRoomNumber->setText(QString::fromStdString(editingRoom->getRoomName()));
        comboBoxRoomType->setCurrentIndex(editingRoom->getRoomType());
        doubleSpinBoxRentPrice->setValue(editingRoom->getMonthlyRent());
        plainTextEditDescription->setPlainText(QString::fromStdString(formatSpace(editingRoom->getDescription())));
        comboBoxStatus->setCurrentIndex(editingRoom->getStatus());
    }
}

AddRoomDiag::~AddRoomDiag() {}

void AddRoomDiag::on_buttonBox_accepted() {
    string roomName = lineEditRoomNumber->text().toStdString();
    int roomType = comboBoxRoomType->currentIndex();
    double monthlyRent = doubleSpinBoxRentPrice->value();
    string description = plainTextEditDescription->toPlainText().toStdString();
    int status = comboBoxStatus->currentIndex();

    if (roomName.empty()){
        QMessageBox::warning(this, "Lỗi nhập liệu", "Số phòng là bắt buộc.");
        return;
    }

    if (editingRoom != nullptr) {
        Room newRoom(editingRoom->getId(), roomName, roomType, monthlyRent, description, status);
        DataManager::getInstance().getRoomManager().update(editingRoom->getId(), newRoom);
    }
    else DataManager::getInstance().getRoomManager().addRoom(roomName, roomType, monthlyRent, " " + description, status);
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
