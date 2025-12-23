#ifndef DATAMANAGER_H
#define DATAMANAGER_H
#include <iostream>
#include <Core/cVector.h>
#include <Data/Contract.h>
#include <Data/Room.h>
#include <Data/Tenant.h>
#include <Data/Bill.h>
#include <Data/Service.h>
#include <Data/ServiceType.h>
#include <Data/Rent.h>
#include <Secure/DataSign.h>

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
    DataManager(const DataManager&) = delete;
    DataManager& operator=(const DataManager&) = delete;
    
    static DataManager& getInstance();

    void loadAllData();
    void saveAllData();

    BillManager& getBillManager() { return billM; }
    ContractManager& getContractManager() { return contractM; }
    RoomManager& getRoomManager() { return roomM; }
    TenantManager& getTenantManager() { return tenantM; }
    ServiceManager& getServiceManager() { return serviceM; }
    ServiceTypeManager& getServiceTypeManager() { return serviceTypeM; }
    RentManager& getRentManager() { return rentM; }
    
    Contract* getContractFromTenant(int tenantId);
    Tenant* getMainTenantFromContract(int contractId);
    Room* getRoomFromContract(int contractId);
    QStringList getAllServices(int billId);
    Vector<Tenant> getAllNoRoomTenants();

    bool isContractDisabled(int contractId);
    int isTenantRenting(int tenantId); // 0: not 1: main tenant 2: co-tenant
    
private:
    DataManager();
    ~DataManager() = default;

    BillManager billM;
    ContractManager contractM;
    RoomManager roomM;
    TenantManager tenantM;
    ServiceManager serviceM;
    ServiceTypeManager serviceTypeM;
    RentManager rentM;
    
    bool dataLoaded = false;
};

#endif // DATAMANAGER_H