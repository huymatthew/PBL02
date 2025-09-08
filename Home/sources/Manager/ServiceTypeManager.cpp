#include <Manager/ServiceTypeManager.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// Default service types
const vector<pair<string, double>> ServiceTypeManager::DEFAULT_SERVICE_TYPES = {
    {"Electricity", 3500.0},
    {"Water", 20000.0},
    {"Internet", 200000.0},
    {"Parking", 50000.0},
    {"Cleaning", 100000.0}
};

ServiceTypeManager::ServiceTypeManager() : data_loaded(false) {}

ServiceTypeManager::~ServiceTypeManager() {}

bool ServiceTypeManager::loadFromDatabase() {
    cout << "\033[1;32m*Loading service types from database...\033[0m" << endl;
    ifstream file("C:\\Qt\\Project\\FirstProject\\Home\\database\\service_types.dat");
    if (!file) {
        cerr << "Error opening service_types.dat for reading." << endl;
        return false;
    }
    
    serviceTypes.clear();
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        int serviceType;
        string name;
        double price;
        
        if (!(iss >> serviceType >> name >> price)) {
            cerr << "Error reading line: " << line << endl;
            continue;
        }
        
        ServiceType serviceTypeObj(serviceType, name, price);
        serviceTypes.push_back(serviceTypeObj);
        cout << "- Loaded service type: " << serviceType << " - " << name << endl;
    }
    
    data_loaded = true;
    return true;
}

bool ServiceTypeManager::saveToDatabase() {
    cout << "\033[1;33m*Saving service types to database...\033[0m" << endl;
    ofstream file("C:\\Qt\\Project\\FirstProject\\Home\\database\\service_types.dat", ios::out | ios::trunc);
    if (!file) {
        cerr << "Error opening service_types.dat for writing." << endl;
        return false;
    }
    
    for (const auto& serviceType : serviceTypes) {
        file << serviceType.getServiceType() << " "
             << serviceType.getName() << " "
             << serviceType.getPrice() << endl;
        cout << "~ Saved service type: " << serviceType.getServiceType() << " - " << serviceType.getName() << endl;
    }
    
    return true;
}

bool ServiceTypeManager::addServiceType(const ServiceType& serviceType) {
    if (serviceTypeExists(serviceType.getServiceType())) {
        cerr << "Service type ID already exists: " << serviceType.getServiceType() << endl;
        return false;
    }
    
    if (serviceTypeNameExists(serviceType.getName())) {
        cerr << "Service type name already exists: " << serviceType.getName() << endl;
        return false;
    }
    
    serviceTypes.push_back(serviceType);
    cout << "+ Added service type: " << serviceType.getServiceType() << " - " << serviceType.getName() << endl;
    return true;
}

bool ServiceTypeManager::addServiceType(int serviceType, const string& name, double price) {
    ServiceType newServiceType(serviceType, name, price);
    return addServiceType(newServiceType);
}

bool ServiceTypeManager::removeServiceType(int serviceType) {
    auto it = findServiceTypeIterator(serviceType);
    if (it != serviceTypes.end()) {
        cout << "- Removed service type: " << serviceType << " - " << it->getName() << endl;
        serviceTypes.erase(it);
        return true;
    }
    cerr << "Service type not found for removal: " << serviceType << endl;
    return false;
}

bool ServiceTypeManager::updateServiceType(int serviceType, const ServiceType& updatedServiceType) {
    auto it = findServiceTypeIterator(serviceType);
    if (it != serviceTypes.end()) {
        *it = updatedServiceType;
        cout << "* Updated service type: " << serviceType << endl;
        return true;
    }
    cerr << "Service type not found for update: " << serviceType << endl;
    return false;
}

ServiceType* ServiceTypeManager::getServiceType(int serviceType) {
    auto it = findServiceTypeIterator(serviceType);
    if (it != serviceTypes.end()) {
        return &(*it);
    }
    return nullptr;
}

ServiceType* ServiceTypeManager::getServiceTypeByName(const string& name) {
    for (auto& serviceType : serviceTypes) {
        if (serviceType.getName() == name) {
            return &serviceType;
        }
    }
    return nullptr;
}

vector<ServiceType> ServiceTypeManager::getAllServiceTypes() const {
    return serviceTypes;
}

bool ServiceTypeManager::serviceTypeExists(int serviceType) const {
    for (const auto& st : serviceTypes) {
        if (st.getServiceType() == serviceType) {
            return true;
        }
    }
    return false;
}

bool ServiceTypeManager::serviceTypeNameExists(const string& name) const {
    for (const auto& st : serviceTypes) {
        if (st.getName() == name) {
            return true;
        }
    }
    return false;
}

int ServiceTypeManager::getServiceTypeCount() const {
    return serviceTypes.size();
}

bool ServiceTypeManager::updateServiceTypePrice(int serviceType, double newPrice) {
    auto it = findServiceTypeIterator(serviceType);
    if (it != serviceTypes.end()) {
        it->setPrice(newPrice);
        cout << "* Updated price for service type " << serviceType << " to " << newPrice << endl;
        return true;
    }
    return false;
}

double ServiceTypeManager::getServiceTypePrice(int serviceType) const {
    for (const auto& st : serviceTypes) {
        if (st.getServiceType() == serviceType) {
            return st.getPrice();
        }
    }
    return 0.0;
}

string ServiceTypeManager::getServiceTypeName(int serviceType) const {
    for (const auto& st : serviceTypes) {
        if (st.getServiceType() == serviceType) {
            return st.getName();
        }
    }
    return "";
}

vector<ServiceType> ServiceTypeManager::searchServiceTypes(const string& keyword) {
    vector<ServiceType> result;
    for (const auto& serviceType : serviceTypes) {
        if (serviceType.getName().find(keyword) != string::npos ||
            to_string(serviceType.getServiceType()).find(keyword) != string::npos) {
            result.push_back(serviceType);
        }
    }
    return result;
}

vector<ServiceType> ServiceTypeManager::getServiceTypesByPriceRange(double minPrice, double maxPrice) const {
    vector<ServiceType> result;
    for (const auto& serviceType : serviceTypes) {
        if (serviceType.getPrice() >= minPrice && serviceType.getPrice() <= maxPrice) {
            result.push_back(serviceType);
        }
    }
    return result;
}

vector<ServiceType> ServiceTypeManager::getServiceTypesSortedByPrice(bool ascending) const {
    vector<ServiceType> sortedTypes = serviceTypes;
    sort(sortedTypes.begin(), sortedTypes.end(),
         [ascending](const ServiceType& a, const ServiceType& b) {
             return ascending ? a.getPrice() < b.getPrice() :
                               a.getPrice() > b.getPrice();
         });
    return sortedTypes;
}

vector<ServiceType> ServiceTypeManager::getServiceTypesSortedByName() const {
    vector<ServiceType> sortedTypes = serviceTypes;
    sort(sortedTypes.begin(), sortedTypes.end(),
         [](const ServiceType& a, const ServiceType& b) {
             return a.getName() < b.getName();
         });
    return sortedTypes;
}

vector<ServiceType> ServiceTypeManager::getServiceTypesSortedById() const {
    vector<ServiceType> sortedTypes = serviceTypes;
    sort(sortedTypes.begin(), sortedTypes.end(),
         [](const ServiceType& a, const ServiceType& b) {
             return a.getServiceType() < b.getServiceType();
         });
    return sortedTypes;
}

double ServiceTypeManager::getMaxPrice() const {
    if (serviceTypes.empty()) return 0.0;
    
    double maxPrice = serviceTypes[0].getPrice();
    for (const auto& serviceType : serviceTypes) {
        if (serviceType.getPrice() > maxPrice) {
            maxPrice = serviceType.getPrice();
        }
    }
    return maxPrice;
}

double ServiceTypeManager::getMinPrice() const {
    if (serviceTypes.empty()) return 0.0;
    
    double minPrice = serviceTypes[0].getPrice();
    for (const auto& serviceType : serviceTypes) {
        if (serviceType.getPrice() < minPrice) {
            minPrice = serviceType.getPrice();
        }
    }
    return minPrice;
}

double ServiceTypeManager::getAveragePrice() const {
    if (serviceTypes.empty()) return 0.0;
    
    double total = 0.0;
    for (const auto& serviceType : serviceTypes) {
        total += serviceType.getPrice();
    }
    return total / serviceTypes.size();
}

double ServiceTypeManager::getTotalPriceSum() const {
    double total = 0.0;
    for (const auto& serviceType : serviceTypes) {
        total += serviceType.getPrice();
    }
    return total;
}

bool ServiceTypeManager::isValidServiceTypeName(const string& name) const {
    return !isStringEmpty(name) && name.length() <= 50;
}

bool ServiceTypeManager::isValidPrice(double price) const {
    return price >= 0.0;
}

vector<int> ServiceTypeManager::getAllServiceTypeIds() const {
    vector<int> ids;
    for (const auto& serviceType : serviceTypes) {
        ids.push_back(serviceType.getServiceType());
    }
    return ids;
}

vector<string> ServiceTypeManager::getAllServiceTypeNames() const {
    vector<string> names;
    for (const auto& serviceType : serviceTypes) {
        names.push_back(serviceType.getName());
    }
    return names;
}

vector<double> ServiceTypeManager::getAllServiceTypePrices() const {
    vector<double> prices;
    for (const auto& serviceType : serviceTypes) {
        prices.push_back(serviceType.getPrice());
    }
    return prices;
}

bool ServiceTypeManager::initializeDefaultServiceTypes() {
    cout << "\033[1;36m*Initializing default service types...\033[0m" << endl;
    bool success = true;
    for (int i = 0; i < DEFAULT_SERVICE_TYPES.size(); ++i) {
        const auto& defaultType = DEFAULT_SERVICE_TYPES[i];
        if (!addServiceType(i, defaultType.first, defaultType.second)) {
            success = false;
        }
    }
    return success;
}

bool ServiceTypeManager::addDefaultServiceType(const string& name, double defaultPrice) {
    // Find next available ID
    int newId = 0;
    for (const auto& serviceType : serviceTypes) {
        if (serviceType.getServiceType() >= newId) {
            newId = serviceType.getServiceType() + 1;
        }
    }
    return addServiceType(newId, name, defaultPrice);
}

// Private helper methods
vector<ServiceType>::iterator ServiceTypeManager::findServiceTypeIterator(int serviceType) {
    for (auto it = serviceTypes.begin(); it != serviceTypes.end(); ++it) {
        if (it->getServiceType() == serviceType) {
            return it;
        }
    }
    return serviceTypes.end();
}

void ServiceTypeManager::sortServiceTypesById() {
    sort(serviceTypes.begin(), serviceTypes.end(),
         [](const ServiceType& a, const ServiceType& b) {
             return a.getServiceType() < b.getServiceType();
         });
}

string ServiceTypeManager::trimString(const string& str) const {
    size_t start = str.find_first_not_of(" \t\n\r");
    if (start == string::npos) return "";
    size_t end = str.find_last_not_of(" \t\n\r");
    return str.substr(start, end - start + 1);
}

bool ServiceTypeManager::isStringEmpty(const string& str) const {
    return trimString(str).empty();
}
