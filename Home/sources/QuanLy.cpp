#include <QuanLy.h>
#include <iostream>

#include <Dialogs/AddTenantDiag.h>
#include <Dialogs/AddRoomDiag.h>
#include <Dialogs/AddContractDiag.h>
#include <Dialogs/AddBillDiag.h>

#include <QStandardItem>
#include <QStandardItemModel>
#include <QDebug>
#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
using namespace std;

QuanLy::QuanLy(QMainWindow *mainWindow) : manager(), mainWindow(mainWindow)
{
    cout << "\033[1;36mQuanLy initialized.\033[0m" << endl;
    setupUi(mainWindow);
    timeUpdate();
    signalAndSlotConnect();
    manager.loadAllData();
    onChangedTabActive(0);

    cout << "\033[1;31m++++++++++++++++++++++++++++++++++++++++++++++++++\033[0m" << endl;
}

QuanLy::~QuanLy()
{
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    manager.saveAllData();
    cout << "\033[1;31m=== QuanLy destroyed. ===\033[0m" << endl;
}

void QuanLy::timeUpdate()
{
    dateTimeLabel->setText(QDateTime::currentDateTime().toString("hh:mm:ss dd/MM/yyyy"));
    QTimer *timer = new QTimer(mainWindow);
    QObject::connect(timer, &QTimer::timeout, [this]()
                     { dateTimeLabel->setText(QDateTime::currentDateTime().toString("hh:mm:ss dd/MM/yyyy")); });
    timer->start(1000);
}

void QuanLy::signalAndSlotConnect()
{
    QObject::connect(mainTabWidget, &QTabWidget::currentChanged,
                     [this](int index)
                     { this->onChangedTabActive(index); });
    QObject::connect(tenantsTableView, &QTableView::doubleClicked, [this](const QModelIndex &index)
                     { onShowTenantDetails(index.siblingAtColumn(0).data().toInt()); });
    QObject::connect(roomsTableView, &QTableView::doubleClicked, [this](const QModelIndex &index)
                     { onShowRoomDetails(index.siblingAtColumn(0).data().toInt()); });
    QObject::connect(actionQuickAddTenant, &QAction::triggered, [this]()
                     { addTenantCall(); });
    QObject::connect(actionQuickAddRoom, &QAction::triggered, [this]()
                     { addRoomCall(); });
    QObject::connect(actionQuickAddContract, &QAction::triggered, [this]()
                     { addContractCall(); });
    QObject::connect(actionQuickAddBill, &QAction::triggered, [this]()
                     { addBillCall(); });

    QObject::connect(deleteTenantButton, &QPushButton::clicked, [this]()
                     { removeTenantCall(); });
    QObject::connect(deleteRoomButton, &QPushButton::clicked, [this]()
                     { removeRoomCall(); });
}
// TabWidget
void QuanLy::onChangedTabActive(int index)
{
    switch (index)
    {
    case 0:
        loadRoomView();
        break;
    case 1:
        loadTenantView();
        break;
    case 2:
        loadContractView();
        break;
    case 3:
        paymentsTableView->setModel(manager.billM.getBillsAsModel());
        break;
    default:
        cerr << "Invalid tab index: " << index << endl;
        break;
    }
}

void QuanLy::onShowTenantDetails(int tenantId){
    Tenant *tenant = manager.tenantM.getTenant(tenantId);
    if (!tenant)
    {
        cerr << "Tenant ID " << tenantId << " not found." << endl;
        return;
    }
    Room* tenant_room = manager.getRoomFromTenant(tenantId);
    if(tenant_room){
        cout << "Tenant " << tenant->getFullName() << " is in room " << tenant_room->getRoomName() << endl;
        tenantRoom->setText(QString::fromStdString(tenant_room->getRoomName()));}
    else
        tenantRoom->setText("No Room");

    manager.tenantM.setTenantSelected(tenant);
    tenantNameEdit->setText(QString::fromStdString(tenant->getFullName()));
    tenantIdEdit->setText(QString::fromStdString(tenant->getIdentityCard()));
    tenantPhoneEdit->setText(QString::fromStdString(tenant->getPhone()));
    comboBox->setCurrentIndex(tenant->getGender());
    dateOfBirth->setDate(QDate::fromString(QString::fromStdString(tenant->getDateOfBirth()), "ddMMyyyy"));
}
void QuanLy::onShowRoomDetails(int roomId)
{
    Room *room = manager.roomM.getRoom(roomId);
    if (!room)
    {
        cerr << "Room ID " << roomId << " not found." << endl;
        return;
    }
    manager.roomM.setRoomSelected(room);
    roomNumberEdit->setText(QString::fromStdString(room->getRoomName()));
    roomDescEdit->setText(QString::fromStdString(room->getDescription()));
    roomPriceSpinBox->setValue(room->getMonthlyRent());

    roomTypeComboBox->setCurrentIndex(room->getRoomType());
    roomStatusComboBox->setCurrentIndex(room->getStatus());
}
// Load
void QuanLy::loadTenantView()
{
    manager.tenantM.setTenantSelected(nullptr);
    tenantsTableView->setModel(manager.tenantM.getTenantsAsModel());
}
void QuanLy::loadRoomView()
{
    manager.roomM.setRoomSelected(nullptr);
    roomsTableView->setModel(manager.roomM.getRoomsAsModel());
}
void QuanLy::loadContractView()
{
    // Sửa lại cột "Mã Phòng" thành "Phòng"
    QStandardItemModel* model = manager.contractM.getContractsAsModel();
    model->setHeaderData(1, Qt::Horizontal, "Phòng");
    for (int row = 0; row < model->rowCount(); ++row) {
        QStandardItem *item = model->item(row, 1);
        if (item) {
            string newItem = manager.roomM.getRoom(item->text().toInt())->getRoomName();
            item->setData(QString::fromStdString(newItem), Qt::DisplayRole);
        }
    }
    contractsTableView->setModel(model);
}

// Add
void QuanLy::addTenantCall()
{
    AddTenantDiag addTenantDialog(mainWindow, manager.tenantM);
    addTenantDialog.exec();
    loadTenantView();
}
void QuanLy::addRoomCall()
{
    AddRoomDiag addRoomDialog(mainWindow, manager.roomM);
    addRoomDialog.exec();
    loadRoomView();
}
void QuanLy::addBillCall()
{
    AddBillDialog addBillDialog(mainWindow, &manager);
    addBillDialog.setFixedSize(700, 800);
    if (manager.roomM.getRoomSelected()) {
        addBillDialog.setRoom(manager.roomM.getRoomSelected()->getRoomId());
        addBillDialog.exec();
        paymentsTableView->setModel(manager.billM.getBillsAsModel());
    } else {
        QMessageBox::warning(mainWindow, "Add Bill", "Please select a room to add a bill.");
    }
    
}
void QuanLy::addContractCall()
{
    AddContractDialog addContractDialog(mainWindow, &manager.contractM, &manager.roomM, &manager.tenantM, &manager.rentM);
    addContractDialog.exec();
    loadContractView();
    loadTenantView();
    loadRoomView();
}
// Remove
void QuanLy::removeTenantCall()
{
    Tenant *tenant = manager.tenantM.getTenantSelected();
    if (tenant == nullptr)
    {
        QMessageBox::warning(mainWindow, "Remove Tenant", "Please select a tenant to remove.");
        return;
    }
    int confirm = QMessageBox::question(mainWindow, "Remove Tenant", "Do you want to delete this tenant?");
    if (confirm == QMessageBox::Yes)
    {
        cout << "Delete User: " << tenant->getFullName() << endl;
        manager.tenantM.removeTenant(tenant->getTenantId());
        loadTenantView();
    }
    else
    {
        cout << "Cancel" << endl;
    }
}

void QuanLy::removeRoomCall()
{
    Room *room = manager.roomM.getRoomSelected();
    if (room == nullptr)
    {
        QMessageBox::warning(mainWindow, "Remove Room", "Please select a room to remove.");
        return;
    }
    int confirm = QMessageBox::question(mainWindow, "Remove Room", "Do you want to delete this room?");
    if (confirm == QMessageBox::Yes)
    {
        cout << "Delete Room: " << room->getRoomName() << endl;
        manager.roomM.removeRoom(room->getRoomId());
        loadRoomView();
    }
    else
    {
        cout << "Cancel" << endl;
    }
}