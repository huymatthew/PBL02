#include <Manager/DataManager.h>
using namespace std;


DataManager::DataManager() {}

DataManager& DataManager::getInstance() {
    static DataManager instance;
    return instance;
}

void DataManager::loadAllData() {
    if (!dataLoaded) {
        cout << "\033[1;32mLoading database...\033[0m" << endl;
        billM.loadFromDatabase();
        contractM.loadFromDatabase();
        roomM.loadFromDatabase();
        tenantM.loadFromDatabase();
        serviceM.loadFromDatabase();
        serviceTypeM.loadFromDatabase();
        rentM.loadFromDatabase();
        dataLoaded = true;
        cout << "\033[1;32mDatabase loaded successfully.\033[0m" << endl;
    }
}

void DataManager::saveAllData() {
    if (dataLoaded) {
        cout << "\033[1;31mSaving database...\033[0m" << endl;
        billM.saveToDatabase();
        contractM.saveToDatabase();
        roomM.saveToDatabase();
        tenantM.saveToDatabase();
        serviceM.saveToDatabase();
        rentM.saveToDatabase();
        dataLoaded = false;
        cout << "\033[1;31mDatabase saved successfully.\033[0m" << endl;
    }
}
Tenant* DataManager::getMainTenantFromContract(int contractId) {
    for (const auto &rent : rentM.rents) {
        if (rent.getIsRepresentative()) {
            Tenant* tenant = tenantM.get(rent.getTenantId());
            if (tenant) {
                return tenant;
            } else {
                cerr << "Tenant not found for contract ID: " << contractId << endl;
                return nullptr;
            }
        }
    }
    return nullptr;
}

Room* DataManager::getRoomFromTenant(int tenantId) {
    for (const auto &rent : rentM.rents) {
        if (rent.getTenantId() == tenantId) {
            int roomId = rentM.getRoomIdByTenant(tenantId);
            Room* room = roomM.get(roomId);
            if (room) {
                return room;
            } else {
                cerr << "Room not found for tenant ID: " << tenantId << endl;
                return nullptr;
            }
        }
    }
    return nullptr;
}