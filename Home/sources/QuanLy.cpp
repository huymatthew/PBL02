#include <QuanLy.h>
#include <iostream>

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
                        [this](int index) {
                            this->onChangedTabActive(index);
                        });
}

void QuanLy::onChangedTabActive(int index) {
    switch (index) {
        case 0:
            roomsTableView->setModel(roomManager.getRoomsAsModel());
            break;
        case 1:
            tenantsTableView->setModel(tenantManager.getTenantsAsModel());
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