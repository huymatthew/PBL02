#include <QuanLy.h>
#include <iostream>

#include <Dialogs/AddTenantDiag.h>
#include <Dialogs/AddRoomDiag.h>
#include <Dialogs/AddContractDiag.h>

#include <QStandardItem>
#include <QStandardItemModel>
#include <QDebug>
#include <QMainWindow>
#include <QMessageBox>
using namespace std;

QuanLy::QuanLy(QMainWindow* mainWindow) : mainWindow(mainWindow) {
    cout << "\033[1;36mQuanLy initialized.\033[0m" << endl;
    cout << "\033[1;32mLoading database...\033[0m" << endl;
    setupUi(mainWindow);
    signalAndSlotConnect();
    onChangedTabActive(0);
}

QuanLy::~QuanLy() {
    cout << "\033[1;31m=== QuanLy destroying. ===\033[0m" << endl;
}

void QuanLy::signalAndSlotConnect() {
    QObject::connect(mainTabWidget, &QTabWidget::currentChanged,
                        [this](int index) {this->onChangedTabActive(index);});
    QObject::connect(tenantsTableView, &QTableView::doubleClicked, [this](const QModelIndex &index){
        onShowTenantDetails(index.siblingAtColumn(0).data().toInt());
    });
    QObject::connect(roomsTableView, &QTableView::doubleClicked, [this](const QModelIndex &index){
        onShowRoomDetails(index.siblingAtColumn(0).data().toInt());
    });
    QObject::connect(actionQuickAddTenant, &QAction::triggered, [this]() {addTenantCall();});
    QObject::connect(actionQuickAddRoom, &QAction::triggered, [this]() {addRoomCall();});
    QObject::connect(actionQuickAddContract, &QAction::triggered, [this]() {addContractCall();});

    QObject::connect(deleteTenantButton, &QPushButton::clicked, [this]() {removeTenantCall();});
    QObject::connect(deleteRoomButton, &QPushButton::clicked, [this]() {removeRoomCall();});
}
// TabWidget
void QuanLy::onChangedTabActive(int index) {
    switch (index) {
        case 0:
            loadRoomView();
            break;
        case 1:
            loadTenantView();
            break;
        case 2:
            contractsTableView->setModel(contractManager.getContractsAsModel());
            break;
        case 3:
            paymentsTableView->setModel(billManager.getBillsAsModel());
            break;
        default:
            cerr << "Invalid tab index: " << index << endl;
            break;
    }
}
// Show
void QuanLy::onShowTenantDetails(int tenantId) {
    Tenant* tenant = tenantManager.getTenant(tenantId);
    if (!tenant) {
        cerr << "Tenant ID " << tenantId << " not found." << endl;
        return;
    }
    tenantManager.setTenantSelected(tenant);
    tenantNameEdit->setText(QString::fromStdString(tenant->getFullName()));
    tenantIdEdit->setText(QString::fromStdString(to_string(tenant->getTenantId())));
    tenantPhoneEdit->setText(QString::fromStdString(tenant->getPhone()));
    dateOfBirth->setDate(QDate::fromString(QString::fromStdString(tenant->getDateOfBirth()), "yyyy-MM-dd"));

    int contractId = tenant->getContractId();
    Contract* contract = contractManager.getContract(contractId);
    if (!contract) {
        cerr << "Contract ID " << contractId << " for tenant ID " << tenantId << " not found." << endl;
        return;
    }
    int index = tenantRoomComboBox->findData(contract->getRoomId().c_str());
    if (index != -1) {
        tenantRoomComboBox->setCurrentIndex(index);
    } else {
        tenantRoomComboBox->setCurrentText("No Room Assigned");
    }
}
void QuanLy::onShowRoomDetails(int roomId) {
    Room* room = roomManager.getRoom(roomId);
    if (!room) {
        cerr << "Room ID " << roomId << " not found." << endl;
        return;
    }
    roomManager.setRoomSelected(room);
    roomNumberEdit->setText(QString::fromStdString(room->getRoomName()));
    roomDescEdit->setText(QString::fromStdString(room->getDescription()));
    roomPriceSpinBox->setValue(room->getMonthlyRent());

    roomTypeComboBox->setCurrentIndex(room->getRoomType());
    roomStatusComboBox->setCurrentIndex(room->getStatus());
}
// Load
void QuanLy::loadTenantView() {
    tenantManager.setTenantSelected(nullptr);
    tenantsTableView->setModel(tenantManager.getTenantsAsModel());
    tenantRoomComboBox->clear();
    tenantRoomComboBox->addItem("No Room Assigned", QVariant::fromValue(0));
    for (const auto& room : roomManager.getAllRooms()) {
        tenantRoomComboBox->addItem(QString::fromStdString(room.getRoomName()), QVariant::fromValue(room.getRoomId()));
    }
}
void QuanLy::loadRoomView() {
    roomManager.setRoomSelected(nullptr);
    roomsTableView->setModel(roomManager.getRoomsAsModel());
}

// Add
void QuanLy::addTenantCall(){
    AddTenantDiag addTenantDialog(mainWindow, tenantManager);
    addTenantDialog.exec();
    loadTenantView();
}
void QuanLy::addRoomCall(){
    AddRoomDiag addRoomDialog(mainWindow, roomManager);
    addRoomDialog.exec();
    loadRoomView();
}
void QuanLy::addContractCall(){
    AddContractDialog addContractDialog(mainWindow, &contractManager, &roomManager, &tenantManager);
    addContractDialog.exec();
}
//Remove
void QuanLy::removeTenantCall(){
    Tenant* tenant = tenantManager.getTenantSelected();
    if (tenant == nullptr) {
        QMessageBox::warning(mainWindow, "Remove Tenant", "Please select a tenant to remove.");
        return;
    }
    int confirm = QMessageBox::question(mainWindow,"Remove Tenant" , "Do you want to delete this tenant?");
    if (confirm == QMessageBox::Yes){
        cout << "Delete User: " << tenant->getFullName() << endl;
        tenantManager.removeTenant(tenant->getTenantId());
        loadTenantView();
    }
    else {
        cout << "Cancel" << endl;
    }
}

void QuanLy::removeRoomCall(){
    Room* room = roomManager.getRoomSelected();
    if (room == nullptr) {
        QMessageBox::warning(mainWindow, "Remove Room", "Please select a room to remove.");
        return;
    }
    int confirm = QMessageBox::question(mainWindow, "Remove Room", "Do you want to delete this room?");
    if (confirm == QMessageBox::Yes){
        cout << "Delete Room: " << room->getRoomName() << endl;
        roomManager.removeRoom(room->getRoomId());
        loadRoomView();
    }
    else {
        cout << "Cancel" << endl;
    }
}