#include <Manager/DataManager.h>
#include <set>
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
    if (isContractDisabled(contractId)) {
        cerr << "Get Main Tenant From Contract: Contract is disabled" << endl;
        return nullptr;
    }
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

Contract* DataManager::getContractFromTenant(int tenantId) {
    Contract* selectedContract = nullptr;
    string latestEndDate = "";
    
    for (const auto &rent : rentM.rents) {
        if (rent.getTenantId() == tenantId) {
            int contractId = rent.getContractId();
            Contract* contract = contractM.get(contractId);
            
            if (contract != nullptr) {
                if (contract->getStatus() != 2) {
                    string endDate = contract->getEndDate();
                    if (latestEndDate.empty() || endDate > latestEndDate) {
                        latestEndDate = endDate;
                        selectedContract = contract;
                    }
                }
            }
        }
    }
    
    if (!selectedContract) {
        cerr << "No active contract found for tenant ID: " << tenantId << endl;
    }
    
    return selectedContract;
}

Room* DataManager::getRoomFromContract(int contractId){
    Contract* contract = DataManager::getInstance().getContractManager().get(contractId);
    if (!contract){
        cerr << "Get Room From Contract: Contract Not Found" << endl;
        return nullptr;
    }
    Room* room = DataManager::getInstance().getRoomManager().get(contract->getRoomId());
    if (!room){
        cerr << "Get Room From Contract: Room Not Found" << endl;
        return nullptr;
    }
    return room;
    
}

QStringList DataManager::getAllServices(int billId){
    QStringList serviceList;
    for (auto it = serviceM.items.begin(); it != serviceM.items.end(); ++it)
    {
        if (it->getBillId() == billId){
            ServiceType* detail = serviceTypeM.getServiceType(it->getServiceType());
            if (!detail) {
                cerr << "Get Service Error" << endl;;
                return serviceList;
            }
            QString d = QString::fromStdString(detail->getName()) + ": " + moneyFormat(it->getPrice());
            serviceList << d;
        }
    }
    return serviceList;
}

Vector<Tenant> DataManager::getAllNoRoomTenants() {
    Vector<Tenant> noRoomTenants;
    
    std::set<int> tenantsWithActiveRooms;
    
    for (const auto& rent : rentM.rents) {
        Contract* contract = contractM.get(rent.getContractId());
        if (contract && contract->getStatus() == 1) { 
            tenantsWithActiveRooms.insert(rent.getTenantId());
        }
    }
    
    for (const auto& tenant : tenantM.items) {
        if (tenantsWithActiveRooms.find(tenant.getId()) == tenantsWithActiveRooms.end()) {
            noRoomTenants.push_back(tenant);
        }
    }
    return noRoomTenants;
}

int DataManager::isTenantRenting(int tenantId) {
    for (const auto &rent : rentM.rents) {
        if (rent.getTenantId() == tenantId) {
            if (rent.getIsRepresentative()) {
                return 1; // main tenant
            } else {
                return 2; // co-tenant
            }
        }
    }
    return 0; // not renting
}

bool DataManager::isContractDisabled(int contractId) {
    Contract* contract = contractM.get(contractId);
    if (contract) {
        return contract->getStatus() == 2; // 2: disabled
    }
    cerr << "Contract not found for ID: " << contractId << endl;
    return false;
}