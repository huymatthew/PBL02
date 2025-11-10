#include <Manager/ServiceTypeManager.h>
#include <fstream>

using namespace std;
ServiceTypeManager::ServiceTypeManager() : data_loaded(false) {}

ServiceTypeManager::~ServiceTypeManager() {}

bool ServiceTypeManager::loadFromDatabase() {
    cout << "\033[1;32m*Loading service types from database...\033[0m" << endl;
    ifstream file("./app/database/service_types.dat");
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
ServiceType* ServiceTypeManager::getServiceType(int serviceType) {
    auto it = findServiceTypeIterator(serviceType);
    if (it != serviceTypes.end()) {
        return &(*it);
    }
    return nullptr;
}
string ServiceTypeManager::getServiceTypeName(int serviceType) const {
    for (const auto& serviceTypeObj : serviceTypes) {
        if (serviceTypeObj.getServiceType() == serviceType) {
            return serviceTypeObj.getName();
        }
    }
    return ""; 
}
QStringList ServiceTypeManager::getServiceTypeNamesForComboBox() const {
    QStringList names;
    for (const auto& serviceTypeObj : serviceTypes) {
        names << QString::fromStdString(serviceTypeObj.getName());
    }
    return names;
}
ServiceType* ServiceTypeManager::getServiceTypeByName(const string& name) {
    for (auto& serviceTypeObj : serviceTypes) {
        if (serviceTypeObj.getName() == name) {
            return &serviceTypeObj;
        }
    }
    return nullptr;
}

Vector<ServiceType> ServiceTypeManager::getAllServiceTypes() const {
    return serviceTypes;
}

bool ServiceTypeManager::serviceTypeExists(int serviceType) const {
    for (const auto& serviceTypeObj : serviceTypes) {
        if (serviceTypeObj.getServiceType() == serviceType) {
            return true;
        }
    }
    return false;
}

bool ServiceTypeManager::serviceTypeNameExists(const string& name) const {
    for (const auto& serviceTypeObj : serviceTypes) {
        if (serviceTypeObj.getName() == name) {
            return true;
        }
    }
    return false;
}

int ServiceTypeManager::getServiceTypeCount() const {
    return static_cast<int>(serviceTypes.size());
}

Vector<ServiceType>::iterator ServiceTypeManager::findServiceTypeIterator(int serviceType) {
    for (auto it = serviceTypes.begin(); it != serviceTypes.end(); ++it) {
        if (it->getServiceType() == serviceType) {
            return it;
        }
    }
    return serviceTypes.end();
}