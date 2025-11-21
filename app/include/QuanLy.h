#ifndef QUAN_LY_H
#define QUAN_LY_H

#include <iostream>
#include <QMainWindow>

#include <Data/Bill.h>
#include <Data/Contract.h>
#include <Data/Room.h>
#include <Data/Service.h>
#include <Data/ServiceType.h>
#include <Data/Tenant.h>

#include <Manager/DataManager.h>

#include <admin_main.h>

class QuanLy : public Ui_AdminMainWindow {
public:
    QuanLy(QMainWindow* mainWindow);
    ~QuanLy();

    void signalAndSlotConnect();
    void timeUpdate();

    void onChangedTabActive(int index);

    void onShowTenantDetails(int tenantId);
    void onShowRoomDetails(int roomId);
    void onShowBillDetails(int billId);

    void loadTenantView();
    void loadRoomView();
    void loadContractView();
    void loadChartView();

    void addTenantCall();
    void addRoomCall();
    void addBillCall();
    void addContractCall();

    void editTenantCall();
    void editRoomCall();

    void removeTenantCall();
    void removeRoomCall();

    void genChart();
private:
    DataManager* manager;
    QMainWindow* mainWindow;
};



#endif // QUAN_LY_H