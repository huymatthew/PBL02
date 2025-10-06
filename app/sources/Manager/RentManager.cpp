#include <Data/Rent.h>
#include <Manager/RentManager.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

RentManager::RentManager() : data_loaded(false) {}
RentManager::~RentManager() {}

void RentManager::addRent(int contractId, int tenantId, bool isRepresentative) {
    rents.emplace_back(contractId, tenantId, isRepresentative);
}
bool RentManager::removeRent(int contractId, int tenantId) {
    for (auto it = rents.begin(); it != rents.end(); ++it) {
        if (it->getRoomId() == contractId && it->getTenantId() == tenantId) {
            rents.erase(it);
            return true;
        }
    }
    return false;
}
int RentManager::getTenantIdByContract(int contractId) {
    for (const auto& rent : rents) {
        if (rent.getRoomId() == contractId && rent.getIsRepresentative()) {
            return rent.getTenantId();
        }
    }
    return -1; // Not found
}
int RentManager::getRoomIdByTenant(int tenantId) {
    for (const auto& rent : rents) {
        if (rent.getTenantId() == tenantId) {
            return rent.getRoomId();
        }
    }
    return -1; // Not found
}
void RentManager::loadFromDatabase() {
    cout << "\033[1;32m*Loading rents from database...\033[0m" << endl;
    ifstream file("./app/database/rents.dat");
    if (!file) {
        cerr << "Error opening file for reading." << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        int roomId, tenantId, isRep;
        if (!(iss >> roomId >> tenantId >> isRep)) {
            cerr << "Error reading line: " << line << endl;
            continue;
        }
        rents.emplace_back(roomId, tenantId, isRep != 0);
        cout << "- Loaded rent: Room ID " << roomId << ", Tenant ID " <<
        tenantId << ", Is Representative: " << (isRep != 0) << endl;
    }
    data_loaded = true;
}
void RentManager::saveToDatabase() {
    cout << "\033[1;33m*Saving rents to database...\033[0m" << endl;
    ofstream file("./app/database/rents.dat", ios::out | ios::trunc);
    if (!file) {
        cerr << "Error opening file for writing." << endl;
        return;
    }
    for (const auto& rent : rents) {
        file << rent.getRoomId() << " "
             << rent.getTenantId() << " "
             << (rent.getIsRepresentative() ? 1 : 0) << endl;
        cout << "~ Saved rent: Room ID " << rent.getRoomId() << ", Tenant ID "
             << rent.getTenantId() << ", Is Representative: "
             << (rent.getIsRepresentative() ? 1 : 0) << endl;
    }
}
