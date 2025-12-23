#include <Manager/ServiceManager.h>
#include <Secure/DataSign.h>
using namespace std;

ServiceManager::ServiceManager() : Manager<Service>() {}
ServiceManager::~ServiceManager() {}

bool ServiceManager::loadFromDatabase(bool showLog) {
    cout << "\033[1;32m*Loading services from database...\033[0m" << endl;
    ifstream file("./app/database/services.dat");
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
        items.emplace_back(serviceID, serviceType, billID, quantity, price);
        pk_manager.addKey(serviceID);
        if (showLog) cout << "- Loaded service ID: " << serviceID << endl;
    }
    return true;
}
bool ServiceManager::saveToDatabase(bool showLog) {
    cout << "\033[1;33m*Saving services to database...\033[0m" << endl;
    ofstream file("./app/database/services.dat", ios::out | ios::trunc);
    if (!file) {
        cerr << "Error opening file for writing." << endl;
        return false;
    }
    for (const auto& service : items) {
        file << service.getId() << " "
             << service.getServiceType() << " "
             << service.getBillId() << " "
             << service.getQuantity() << " "
             << service.getPrice() << endl;
        if (showLog) cout << "~ Saved service ID: " << service.getId() << endl;
    }
    if (showLog) cout << items.size() << " services saved." << endl;
    file.close();
    return true;
}

void ServiceManager::quicksave() {
    saveToDatabase(false);
    DataSign::saveDataSign();
}

bool ServiceManager::addService(int serviceType, int billId, int quantity, double price) {
    if (!isValidServiceType(serviceType) || !isValidQuantity(quantity) || !isValidPrice(price)) {
        cerr << "Invalid service parameters." << endl;
        return false;
    }
    int newServiceId = pk_manager.getNextKey();
    Service newService(newServiceId, serviceType, billId, quantity, price);
    return add(newService);
}

int ServiceManager::getNextServiceId() {
    return pk_manager.getNextKey();
}

int ServiceManager::getServiceCountByBill(int billId) const {
    for (const auto& service : items) {
        if (service.getBillId() == billId) {
            return 1;
        }
    }
    return 0;
}
int ServiceManager::getServiceCountByType(int serviceType) const {
    for (const auto& service : items) {
        if (service.getServiceType() == serviceType) {
            return 1;
        }
    }
    return 0;
}

double ServiceManager::getTotalServiceCost(int billId) const {
    double total = 0.0;
    for (const auto& service : items) {
        if (service.getBillId() == billId) {
            total += service.getPrice() * service.getQuantity();
        }
    }
    return total;
}
double ServiceManager::getTotalServiceCostByType(int serviceType) const {
    double total = 0.0;
    for (const auto& service : items) {
        if (service.getServiceType() == serviceType) {
            total += service.getPrice() * service.getQuantity();
        }
    }
    return total;
}
double ServiceManager::getAverageServiceCost() const {
    if (items.empty()) return 0.0;
    double total = 0.0;
    for (const auto& service : items) {
        total += service.getPrice() * service.getQuantity();
    }
    return total / items.size();
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
