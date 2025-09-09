#include <Manager/ServiceTypeManager.h>
#include <fstream>

using namespace std;
ServiceTypeManager::ServiceTypeManager() {
    loadFromDatabase();
}

ServiceTypeManager::~ServiceTypeManager() {
    
}

bool ServiceTypeManager::loadFromDatabase() {
    ifstream file("C:\\Qt\\Project\\FirstProject\\Home\\database\\service_types.dat");
    if (!file) {
        cerr << "Error opening file for reading." << endl;
        return false;
    }
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        int serviceType;
        string name;
        double price;
        if (!(iss >> serviceType >> name >> price)) {
            cerr << "Error reading line: " << line << endl;
            continue; // Skip malformed lines
        }
        if (pk_manager.isKeyInUse(serviceType)) {
            cerr << "Duplicate service type ID found: " << serviceType << endl;
            continue; // Skip duplicate IDs
        }
        serviceTypes.emplace_back(serviceType, name, price);
        pk_manager.addKey(serviceType);
        cout << "- Loaded service type ID: " << serviceType << endl;
    }
    data_loaded = true;
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
    if (!isValidServiceTypeName(serviceType.getName())) {
        cerr << "Invalid service type name: " << serviceType.getName() << endl;
        return false;
    }
    if (!isValidPrice(serviceType.getPrice())) {
        cerr << "Invalid price: " << serviceType.getPrice() << endl;
        return false;
    }
    serviceTypes.push_back(serviceType);
    pk_manager.addKey(serviceType.getServiceType());
    sortServiceTypesById();
    return true;
}
bool ServiceTypeManager::addServiceType(int serviceType, const string& name, double price) {
    if (serviceTypeExists(serviceType)) {
        cerr << "Service type ID already exists: " << serviceType << endl;
        return false;
    }
    if (serviceTypeNameExists(name)) {
        cerr << "Service type name already exists: " << name << endl;
        return false;
    }
    if (!isValidServiceTypeName(name)) {
        cerr << "Invalid service type name: " << name << endl;
        return false;
    }
    if (!isValidPrice(price)) {
        cerr << "Invalid price: " << price << endl;
        return false;
    }
    ServiceType newServiceType(serviceType, name, price);
    serviceTypes.push_back(newServiceType);
    pk_manager.addKey(serviceType);
    sortServiceTypesById();
    return true;
}
bool ServiceTypeManager::updateServiceType(int serviceType, const ServiceType& updatedServiceType) {
    auto it = findServiceTypeIterator(serviceType);
    if (it == serviceTypes.end()) {
        cerr << "Service type ID not found: " << serviceType << endl;
        return false;
    }
    if (updatedServiceType.getServiceType() != serviceType && serviceTypeExists(updatedServiceType.getServiceType())) {
        cerr << "Updated service type ID already exists: " << updatedServiceType.getServiceType() << endl;
        return false;
    }
    if (updatedServiceType.getName() != it->getName() && serviceTypeNameExists(updatedServiceType.getName())) {
        cerr << "Updated service type name already exists: " << updatedServiceType.getName() << endl;
        return false;
    }
    if (!isValidServiceTypeName(updatedServiceType.getName())) {
        cerr << "Invalid service type name: " << updatedServiceType.getName() << endl;
        return false;
    }
    if (!isValidPrice(updatedServiceType.getPrice())) {
        cerr << "Invalid price: " << updatedServiceType.getPrice() << endl;
        return false;
    }
    if (updatedServiceType.getServiceType() != serviceType) {
        pk_manager.releaseKey(it->getServiceType());
        pk_manager.addKey(updatedServiceType.getServiceType());
    }
    *it = updatedServiceType;
    sortServiceTypesById();
    return true;
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
    return pk_manager.isKeyInUse(serviceType);
}
bool ServiceTypeManager::serviceTypeNameExists(const string& name) const {
    for (const auto& serviceType : serviceTypes) {
        if (serviceType.getName() == name) {
            return true;
        }
    }
    return false;
}
int ServiceTypeManager::getServiceTypeCount() const {
    return static_cast<int>(serviceTypes.size());
}

bool ServiceTypeManager::updateServiceTypePrice(int serviceType, double newPrice) {
    if (!isValidPrice(newPrice)) {
        cerr << "Invalid price: " << newPrice << endl;
        return false;
    }
    auto it = findServiceTypeIterator(serviceType);
    if (it == serviceTypes.end()) {
        cerr << "Service type ID not found: " << serviceType << endl;
        return false;
    }
    it->setPrice(newPrice);
    return true;
}
double ServiceTypeManager::getServiceTypePrice(int serviceType) const {
    for (const auto& serviceTypeObj : serviceTypes) {
        if (serviceTypeObj.getServiceType() == serviceType) {
            return serviceTypeObj.getPrice();
        }
    }
    return -1.0; // Indicate not found
}
string ServiceTypeManager::getServiceTypeName(int serviceType) const {
    for (const auto& serviceTypeObj : serviceTypes) {
        if (serviceTypeObj.getServiceType() == serviceType) {
            return serviceTypeObj.getName();
        }
    }
    return ""; // Indicate not found
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
    string trimmedName = trimString(name);
    return !trimmedName.empty() && trimmedName.length() <= 100;
}
bool ServiceTypeManager::isValidPrice(double price) const {
    return price >= 0.0;
}

vector<ServiceType>::iterator ServiceTypeManager::findServiceTypeIterator(int serviceType) {
    for (auto it = serviceTypes.begin(); it != serviceTypes.end(); ++it) {
        if (it->getServiceType() == serviceType) {
            return it;
        }
    }
    return serviceTypes.end();
}
void ServiceTypeManager::sortServiceTypesById() {
    sort(serviceTypes.begin(), serviceTypes.end(), [](const ServiceType& a, const ServiceType& b) {
        return a.getServiceType() < b.getServiceType();
    });
}
string ServiceTypeManager::trimString(const string& str) const {
    size_t first = str.find_first_not_of(' ');
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}
bool ServiceTypeManager::isStringEmpty(const string& str) const {
    return trimString(str).empty();
}

