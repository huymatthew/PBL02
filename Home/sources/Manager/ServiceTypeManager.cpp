#include <Manager/ServiceTypeManager.h>
#include <fstream>

using namespace std;
ServiceTypeManager::ServiceTypeManager() : data_loaded(false) {}

ServiceTypeManager::~ServiceTypeManager() {}

bool ServiceTypeManager::loadFromDatabase() {
    cout << "\033[1;32m*Loading service types from database...\033[0m" << endl;
    ifstream file("./Home/database/service_types.dat");
    if (!file) {
        cerr << "Error opening file for reading." << endl;
        return false;
    }
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        int serviceType;
        string name, unit;
        double price;
        if (!(iss >> serviceType >> name >> price >> unit)) {
            cerr << "Error reading line: " << line << endl;
            continue; 
        }
        serviceTypes.emplace_back(serviceType, name, price, unit);
        cout << "- Loaded service type ID: " << serviceType << endl;
    }
    data_loaded = true;
    return true;
}

double ServiceTypeManager::getServiceTypePrice(int serviceType) const {
    for (const auto& serviceTypeObj : serviceTypes) {
        if (serviceTypeObj.getServiceType() == serviceType) {
            return serviceTypeObj.getPrice();
        }
    }
    return -1.0; 
}
string ServiceTypeManager::getServiceTypeName(int serviceType) const {
    for (const auto& serviceTypeObj : serviceTypes) {
        if (serviceTypeObj.getServiceType() == serviceType) {
            return serviceTypeObj.getName();
        }
    }
    return ""; 
}
vector<ServiceType>::iterator ServiceTypeManager::findServiceTypeIterator(int serviceType) {
    for (auto it = serviceTypes.begin(); it != serviceTypes.end(); ++it) {
        if (it->getServiceType() == serviceType) {
            return it;
        }
    }
    return serviceTypes.end();
}