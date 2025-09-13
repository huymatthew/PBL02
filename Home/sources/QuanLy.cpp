#include <QuanLy.h>
#include <iostream>

#include <Dialogs/AddTenantDiag.h>
#include <Dialogs/AddRoomDiag.h>

#include <QStandardItem>
#include <QStandardItemModel>
#include <QDebug>
#include <QMainWindow>
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
    QObject::connect(actionQuickAddTenant, &QAction::triggered, [this]() {
        AddTenantDiag addTenantDialog(mainWindow, tenantManager);
        addTenantDialog.exec();
        loadTenantView();
    });
    QObject::connect(actionQuickAddRoom, &QAction::triggered, [this]() {
        AddRoomDiag addRoomDialog(mainWindow, roomManager);
        addRoomDialog.exec();
        loadRoomView();
    });

}
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

void QuanLy::onShowTenantDetails(int tenantId) {
    Tenant* tenant = tenantManager.getTenant(tenantId);
    if (!tenant) {
        cerr << "Tenant ID " << tenantId << " not found." << endl;
        return;
    }
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
        tenantRoomComboBox->setCurrentIndex(0);
    }
}
void QuanLy::onShowRoomDetails(int roomId) {
    Room* room = roomManager.getRoom(roomId);
    if (!room) {
        cerr << "Room ID " << roomId << " not found." << endl;
        return;
    }
    roomNumberEdit->setText(QString::fromStdString(room->getRoomName()));
    roomDescEdit->setText(QString::fromStdString(room->getDescription()));
    roomPriceSpinBox->setValue(room->getMonthlyRent());

    roomTypeComboBox->setCurrentIndex(room->getRoomType());
    roomStatusComboBox->setCurrentIndex(room->getStatus());
}
void QuanLy::loadTenantView() {
    tenantsTableView->setModel(tenantManager.getTenantsAsModel());
    tenantRoomComboBox->clear();
    for (const auto& room : roomManager.getAllRooms()) {
        tenantRoomComboBox->addItem(QString::fromStdString(room.getRoomName()), QVariant::fromValue(room.getRoomId()));
    }
}
void QuanLy::loadRoomView() {
    roomsTableView->setModel(roomManager.getRoomsAsModel());
}

