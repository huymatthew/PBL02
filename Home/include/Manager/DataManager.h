#ifndef DATAMANAGER_H
#define DATAMANAGER_H
#include <iostream>
#include <vector>
#include <Data/Contract.h>
#include <Data/Room.h>
#include <Data/Tenant.h>
#include <Data/Bill.h>
#include <Data/Service.h>
#include <Data/ServiceType.h>
#include <Data/Rent.h>

#include <QStandardItemModel>
#include <QString>
#include <QDate>
#include <Core/ExtraFormat.h>
#include <QDebug>

#include <Manager/BillManager.h>
#include <Manager/ContractManager.h>
#include <Manager/RoomManager.h>
#include <Manager/TenantManager.h>
#include <Manager/ServiceManager.h>
#include <Manager/ServiceTypeManager.h>
#include <Manager/RentManager.h>

class DataManager {
public:
    DataManager();
    ~DataManager();
    BillManager billM;
    ContractManager contractM;
    RoomManager roomM;
    TenantManager tenantM;
    ServiceManager serviceM;
    ServiceTypeManager serviceTypeM;
    RentManager rentM;

    void loadAllData();
    void saveAllData();
    Room* getRoomFromTenant(int tenantId);
private:
    bool dataLoaded = false;
};

#endif // DATAMANAGER_H