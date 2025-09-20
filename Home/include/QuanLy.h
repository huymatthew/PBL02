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

#include <Manager/ServiceManager.h>
#include <Manager/RoomManager.h>
#include <Manager/BillManager.h>
#include <Manager/ContractManager.h>
#include <Manager/TenantManager.h>
#include <Manager/ServiceTypeManager.h>

#include <admin_main.h>

class QuanLy : public Ui_AdminMainWindow {
public:
    QuanLy(QMainWindow* mainWindow);
    ~QuanLy();

    void signalAndSlotConnect();

    void onChangedTabActive(int index);
    void onShowTenantDetails(int tenantId);
    void onShowRoomDetails(int roomId);

    void loadTenantView();
    void loadRoomView();

    void addTenantCall();
    void addRoomCall();

    void removeTenantCall();
    void removeRoomCall();
private:
    BillManager billManager;
    ContractManager contractManager;
    RoomManager roomManager;
    ServiceManager serviceManager;
    ServiceTypeManager serviceTypeManager;
    TenantManager tenantManager;

    QMainWindow* mainWindow;
};



#endif // QUAN_LY_H