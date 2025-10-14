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

QuanLy::QuanLy(QMainWindow *mainWindow) : mainWindow(mainWindow)
{
    cout << "\033[1;36mQuanLy initialized.\033[0m" << endl;
    setupUi(mainWindow);
    timeUpdate();
    signalAndSlotConnect();
    manager = &DataManager::getInstance();
    manager->loadAllData();
    onChangedTabActive(0);

    cout << "\033[1;31m++++++++++++++++++++++++++++++++++++++++++++++++++\033[0m" << endl;
}

QuanLy::~QuanLy()
{
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    manager->saveAllData();
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
        paymentsTableView->setModel(manager->getBillManager().getBillsAsModel());
        break;
    default:
        cerr << "Invalid tab index: " << index << endl;
        break;
    }
}

void QuanLy::onShowTenantDetails(int tenantId){
    Tenant *tenant = manager->getTenantManager().get(tenantId);
    if (!tenant)
    {
        cerr << "Tenant ID " << tenantId << " not found." << endl;
        return;
    }
    Room* tenant_room = manager->getRoomFromTenant(tenantId);
    if(tenant_room){
        cout << "Tenant " << tenant->getFullName() << " is in room " << tenant_room->getRoomName() << endl;
        tenantRoom->setText(QString::fromStdString(tenant_room->getRoomName()));}
    else
        tenantRoom->setText("No Room");

    manager->getTenantManager().setTenantSelected(tenant);
    tenantNameEdit->setText(QString::fromStdString(tenant->getFullName()));
    tenantIdEdit->setText(QString::fromStdString(tenant->getIdentityCard()));
    tenantPhoneEdit->setText(QString::fromStdString(tenant->getPhone()));
    comboBox->setCurrentIndex(tenant->getGender());
    dateOfBirth->setDate(QDate::fromString(QString::fromStdString(tenant->getDateOfBirth()), "ddMMyyyy"));
}
void QuanLy::onShowRoomDetails(int roomId)
{
    Room *room = manager->getRoomManager().get(roomId);
    if (!room)
    {
        cerr << "Room ID " << roomId << " not found." << endl;
        return;
    }
    manager->getRoomManager().setRoomSelected(room);
    roomNumberEdit->setText(QString::fromStdString(room->getRoomName()));
    roomDescEdit->setText(QString::fromStdString(room->getDescription()));
    roomPriceSpinBox->setValue(room->getMonthlyRent());

    roomTypeComboBox->setCurrentIndex(room->getRoomType());
    roomStatusComboBox->setCurrentIndex(room->getStatus());
}
// Load
void QuanLy::loadTenantView()
{
    manager->getTenantManager().setTenantSelected(nullptr);
    tenantsTableView->setModel(manager->getTenantManager().getTenantsAsModel());
}
void QuanLy::loadRoomView()
{
    manager->getRoomManager().setRoomSelected(nullptr);
    roomsTableView->setModel(manager->getRoomManager().getRoomsAsModel());
}
void QuanLy::loadContractView()
{
    // Sửa lại cột "Mã Phòng" thành "Phòng"
    QStandardItemModel* model = manager->getContractManager().getContractsAsModel();
    model->setHeaderData(1, Qt::Horizontal, "Phòng");
    for (int row = 0; row < model->rowCount(); ++row) {
        QStandardItem *item = model->item(row, 1);
        if (item) {
            string newItem = manager->getRoomManager().get(item->text().toInt())->getRoomName();
            item->setData(QString::fromStdString(newItem), Qt::DisplayRole);
        }
    }
    contractsTableView->setModel(model);
}

// Add
void QuanLy::addTenantCall()
{
    AddTenantDiag addTenantDialog(mainWindow);
    addTenantDialog.exec();
    loadTenantView();
}
void QuanLy::addRoomCall()
{
    AddRoomDiag addRoomDialog(mainWindow);
    addRoomDialog.exec();
    loadRoomView();
}
void QuanLy::addBillCall()
{
    AddBillDialog addBillDialog(mainWindow);
    addBillDialog.setFixedSize(900, 800);
    if (manager->getRoomManager().getRoomSelected()) {
        addBillDialog.setRoom(manager->getRoomManager().getRoomSelected()->getId());
        addBillDialog.exec();
        paymentsTableView->setModel(manager->getBillManager().getBillsAsModel());
    } else {
        QMessageBox::warning(mainWindow, "Add Bill", "Please select a room to add a bill.");
    }
    
}
void QuanLy::addContractCall()
{
    AddContractDialog addContractDialog(mainWindow);
    addContractDialog.exec();
    loadContractView();
    loadTenantView();
    loadRoomView();
}
// Remove
void QuanLy::removeTenantCall()
{
    Tenant *tenant = manager->getTenantManager().getTenantSelected();
    if (tenant == nullptr)
    {
        QMessageBox::warning(mainWindow, "Remove Tenant", "Please select a tenant to remove.");
        return;
    }
    int confirm = QMessageBox::question(mainWindow, "Remove Tenant", "Do you want to delete this tenant?");
    if (confirm == QMessageBox::Yes)
    {
        cout << "Delete User: " << tenant->getFullName() << endl;
        manager->getTenantManager().remove(tenant->getId());
        loadTenantView();
    }
    else
    {
        cout << "Cancel" << endl;
    }
}

void QuanLy::removeRoomCall()
{
    Room *room = manager->getRoomManager().getRoomSelected();
    if (room == nullptr)
    {
        QMessageBox::warning(mainWindow, "Remove Room", "Please select a room to remove.");
        return;
    }
    int confirm = QMessageBox::question(mainWindow, "Remove Room", "Do you want to delete this room?");
    if (confirm == QMessageBox::Yes)
    {
        cout << "Delete Room: " << room->getRoomName() << endl;
        manager->getRoomManager().remove(room->getId());
        loadRoomView();
    }
    else
    {
        cout << "Cancel" << endl;
    }
}