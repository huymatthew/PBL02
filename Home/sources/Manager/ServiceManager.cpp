#include <Manager/ServiceManager.h>
using namespace std;

ServiceManager::ServiceManager() : data_loaded(false){
    loadFromDatabase();
}

ServiceManager::~ServiceManager(){
    saveToDatabase();
}

bool ServiceManager::loadFromDatabase() {
    cout << "\033[1;32m*Loading rooms from database...\033[0m" << endl;
    ifstream file("C:\\Qt\\Project\\FirstProject\\Home\\database\\services.dat");
    if (!file) {
        cerr << "Error opening file for reading." << endl;
        return false;
    }
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        int serviceID, serviceType, billID, quantity;
        double price;
        if (!(iss >> serviceID >> serviceType >> billID >> quantity >> price)) {
            cerr << "Error reading line: " << line << endl;
            continue;
        }
        if (pk_manager.isKeyInUse(serviceID)) {
            cerr << "Duplicate service ID found: " << serviceID << endl;
            continue; 
        }
        services.emplace_back(serviceID, serviceType, billID, quantity, price);
        pk_manager.addKey(serviceID);
        cout << "- Loaded service ID: " << serviceID << endl;
    }
    return true;
}
bool ServiceManager::saveToDatabase() {
    cout << "\033[1;33m*Saving rooms to database...\033[0m" << endl;
    ofstream file("C:\\Qt\\Project\\FirstProject\\Home\\database\\rooms.dat", ios::out | ios::trunc);
    if (!file) {
        cerr << "Error opening file for writing." << endl;
        return false;
    }
    for (const auto& service : services) {
        file << service.getServiceId() << " "
             << service.getServiceType() << " "
             << service.getBillId() << " "
             << service.getQuantity() << " "
             << service.getPrice() << endl;
        cout << "~ Saved service ID: " << service.getServiceId() << endl;
    }
    return true;
}
bool ServiceManager::addService(const Service& service) {
    if (pk_manager.isKeyInUse(service.getServiceId())) {
        cerr << "Service ID already in use: " << service.getServiceId() << endl;
        return false;
    }
    services.push_back(service);
    pk_manager.addKey(service.getServiceId());
    return true;
}

bool ServiceManager::addService(int serviceType, int billId, int quantity, double price) {
    if (!isValidServiceType(serviceType) || !isValidQuantity(quantity) || !isValidPrice(price)) {
        cerr << "Invalid service parameters." << endl;
        return false;
    }
    int newServiceId = pk_manager.getNextKey();
    Service newService(newServiceId, serviceType, billId, quantity, price);
    services.push_back(newService);
    return true;
}
bool ServiceManager::removeService(int serviceId) {
    auto it = findServiceIterator(serviceId);
    if (it != services.end()) {
        services.erase(it);
        pk_manager.releaseKey(serviceId);
        return true;
    }
    cerr << "Service ID not found: " << serviceId << endl;
    return false;
}
bool ServiceManager::updateService(int serviceId, const Service& updatedService) {
    auto it = findServiceIterator(serviceId);
    if (it != services.end()) {
        if (serviceId != updatedService.getServiceId() && pk_manager.isKeyInUse(updatedService.getServiceId())) {
            cerr << "Updated service ID already in use: " << updatedService.getServiceId() << endl;
            return false;
        }
        *it = updatedService;
        return true;
    }
    cerr << "Service ID not found: " << serviceId << endl;
    return false;
}

Service* ServiceManager::getService(int serviceId) {
    auto it = findServiceIterator(serviceId);
    if (it != services.end()) {
        return &(*it);
    }
    return nullptr;
}

bool ServiceManager::serviceExists(int serviceId) const {
    return pk_manager.isKeyInUse(serviceId);
}
int ServiceManager::getServiceCount() const {
    return services.size();
}
int ServiceManager::getServiceCountByBill(int billId) const {
    for (const auto& service : services) {
        if (service.getBillId() == billId) {
            return 1;
        }
    }
    return 0;
}
int ServiceManager::getServiceCountByType(int serviceType) const {
    for (const auto& service : services) {
        if (service.getServiceType() == serviceType) {
            return 1;
        }
    }
    return 0;
}

double ServiceManager::getTotalServiceCost(int billId) const {
    double total = 0.0;
    for (const auto& service : services) {
        if (service.getBillId() == billId) {
            total += service.getPrice() * service.getQuantity();
        }
    }
    return total;
}
double ServiceManager::getTotalServiceCostByType(int serviceType) const {
    double total = 0.0;
    for (const auto& service : services) {
        if (service.getServiceType() == serviceType) {
            total += service.getPrice() * service.getQuantity();
        }
    }
    return total;
}
double ServiceManager::getAverageServiceCost() const {
    if (services.empty()) return 0.0;
    double total = 0.0;
    for (const auto& service : services) {
        total += service.getPrice() * service.getQuantity();
    }
    return total / services.size();
}

bool ServiceManager::isValidServiceType(int serviceType) const {
    return serviceType > 0; 
}
bool ServiceManager::isValidQuantity(int quantity) const {
    return quantity > 0;
}
bool ServiceManager::isValidPrice(double price) const {
    return price >= 0.0;
}

vector<Service>::iterator ServiceManager::findServiceIterator(int serviceId) {
    for (const auto& service : services) {
        if (service.getServiceId() == serviceId) {
            return services.begin() + (&service - &services[0]);
        }
    }
    return services.end();
}