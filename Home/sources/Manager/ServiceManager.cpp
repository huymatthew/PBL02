#include <Manager/ServiceManager.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <numeric>
using namespace std;

ServiceManager::ServiceManager() : data_loaded(false) {}

ServiceManager::~ServiceManager() {}

bool ServiceManager::loadFromDatabase() {
    cout << "\033[1;32m*Loading services from database...\033[0m" << endl;
    ifstream file("C:\\Qt\\Project\\FirstProject\\Home\\database\\services.dat");
    if (!file) {
        cerr << "Error opening services.dat for reading." << endl;
        return false;
    }
    
    services.clear();
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        int serviceId, serviceType, billId, quantity;
        double price;
        
        if (!(iss >> serviceId >> serviceType >> billId >> quantity >> price)) {
            cerr << "Error reading line: " << line << endl;
            continue;
        }
        
        Service service(serviceId, serviceType, billId, quantity, price);
        services.push_back(service);
        cout << "- Loaded service ID: " << serviceId << endl;
    }
    
    data_loaded = true;
    return true;
}

bool ServiceManager::saveToDatabase() {
    cout << "\033[1;33m*Saving services to database...\033[0m" << endl;
    ofstream file("C:\\Qt\\Project\\FirstProject\\Home\\database\\services.dat", ios::out | ios::trunc);
    if (!file) {
        cerr << "Error opening services.dat for writing." << endl;
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
    if (serviceExists(service.getServiceId())) {
        cerr << "Service ID already exists: " << service.getServiceId() << endl;
        return false;
    }
    
    services.push_back(service);
    cout << "+ Added service ID: " << service.getServiceId() << endl;
    return true;
}

bool ServiceManager::addService(int serviceType, int billId, int quantity, double price) {
    // Generate new ID
    int newId = services.empty() ? 1 : services.back().getServiceId() + 1;
    Service newService(newId, serviceType, billId, quantity, price);
    return addService(newService);
}

bool ServiceManager::removeService(int serviceId) {
    auto it = findServiceIterator(serviceId);
    if (it != services.end()) {
        services.erase(it);
        cout << "- Removed service ID: " << serviceId << endl;
        return true;
    }
    cerr << "Service not found for removal: " << serviceId << endl;
    return false;
}

bool ServiceManager::updateService(int serviceId, const Service& updatedService) {
    auto it = findServiceIterator(serviceId);
    if (it != services.end()) {
        *it = updatedService;
        cout << "* Updated service ID: " << serviceId << endl;
        return true;
    }
    cerr << "Service not found for update: " << serviceId << endl;
    return false;
}

Service* ServiceManager::getService(int serviceId) {
    auto it = findServiceIterator(serviceId);
    if (it != services.end()) {
        return &(*it);
    }
    return nullptr;
}

vector<Service> ServiceManager::getServicesByBill(int billId) const{
    vector<Service> result;
    for (const auto& service : services) {
        if (service.getBillId() == billId) {
            result.push_back(service);
        }
    }
    return result;
}

vector<Service> ServiceManager::getServicesByType(int serviceType) const {
    vector<Service> result;
    for (const auto& service : services) {
        if (service.getServiceType() == serviceType) {
            result.push_back(service);
        }
    }
    return result;
}

vector<Service> ServiceManager::getAllServices() const {
    return services;
}

bool ServiceManager::serviceExists(int serviceId) const {
    for (const auto& service : services) {
        if (service.getServiceId() == serviceId) {
            return true;
        }
    }
    return false;
}

int ServiceManager::getServiceCount() const {
    return services.size();
}

int ServiceManager::getServiceCountByBill(int billId) const {
    int count = 0;
    for (const auto& service : services) {
        if (service.getBillId() == billId) {
            count++;
        }
    }
    return count;
}

int ServiceManager::getServiceCountByType(int serviceType) const {
    int count = 0;
    for (const auto& service : services) {
        if (service.getServiceType() == serviceType) {
            count++;
        }
    }
    return count;
}

double ServiceManager::getTotalServiceCost(int billId) const {
    double total = 0.0;
    for (const auto& service : services) {
        if (service.getBillId() == billId) {
            total += service.getQuantity() * service.getPrice();
        }
    }
    return total;
}

double ServiceManager::getTotalServiceCostByType(int serviceType) const {
    double total = 0.0;
    for (const auto& service : services) {
        if (service.getServiceType() == serviceType) {
            total += service.getQuantity() * service.getPrice();
        }
    }
    return total;
}

double ServiceManager::getAverageServiceCost() const {
    if (services.empty()) return 0.0;
    
    double total = 0.0;
    for (const auto& service : services) {
        total += service.getQuantity() * service.getPrice();
    }
    return total / services.size();
}

int ServiceManager::getTotalQuantityByType(int serviceType) const {
    int total = 0;
    for (const auto& service : services) {
        if (service.getServiceType() == serviceType) {
            total += service.getQuantity();
        }
    }
    return total;
}

int ServiceManager::getTotalQuantityByBill(int billId) const {
    int total = 0;
    for (const auto& service : services) {
        if (service.getBillId() == billId) {
            total += service.getQuantity();
        }
    }
    return total;
}

double ServiceManager::getAverageQuantityByType(int serviceType) const {
    vector<Service> typeServices = getServicesByType(serviceType);
    if (typeServices.empty()) return 0.0;
    
    int total = 0;
    for (const auto& service : typeServices) {
        total += service.getQuantity();
    }
    return static_cast<double>(total) / typeServices.size();
}

double ServiceManager::getMaxPriceByType(int serviceType) const {
    double maxPrice = 0.0;
    bool found = false;
    for (const auto& service : services) {
        if (service.getServiceType() == serviceType) {
            if (!found || service.getPrice() > maxPrice) {
                maxPrice = service.getPrice();
                found = true;
            }
        }
    }
    return maxPrice;
}

double ServiceManager::getMinPriceByType(int serviceType) const {
    double minPrice = 0.0;
    bool found = false;
    for (const auto& service : services) {
        if (service.getServiceType() == serviceType) {
            if (!found || service.getPrice() < minPrice) {
                minPrice = service.getPrice();
                found = true;
            }
        }
    }
    return minPrice;
}

double ServiceManager::getAveragePriceByType(int serviceType) const {
    vector<Service> typeServices = getServicesByType(serviceType);
    if (typeServices.empty()) return 0.0;
    
    double total = 0.0;
    for (const auto& service : typeServices) {
        total += service.getPrice();
    }
    return total / typeServices.size();
}

vector<Service> ServiceManager::searchServices(const string& keyword) {
    vector<Service> result;
    // Since Service doesn't have text fields, search by converting numbers to string
    for (const auto& service : services) {
        if (to_string(service.getServiceId()).find(keyword) != string::npos ||
            to_string(service.getBillId()).find(keyword) != string::npos) {
            result.push_back(service);
        }
    }
    return result;
}

vector<Service> ServiceManager::getServicesByPriceRange(double minPrice, double maxPrice) const {
    vector<Service> result;
    for (const auto& service : services) {
        if (service.getPrice() >= minPrice && service.getPrice() <= maxPrice) {
            result.push_back(service);
        }
    }
    return result;
}

vector<Service> ServiceManager::getServicesByQuantityRange(int minQuantity, int maxQuantity) const {
    vector<Service> result;
    for (const auto& service : services) {
        if (service.getQuantity() >= minQuantity && service.getQuantity() <= maxQuantity) {
            result.push_back(service);
        }
    }
    return result;
}

bool ServiceManager::addMultipleServices(const vector<Service>& newServices) {
    bool success = true;
    for (const auto& service : newServices) {
        if (!addService(service)) {
            success = false;
        }
    }
    return success;
}

bool ServiceManager::removeServicesByBill(int billId) {
    auto it = services.begin();
    bool removed = false;
    while (it != services.end()) {
        if (it->getBillId() == billId) {
            cout << "- Removed service ID " << it->getServiceId() << " from bill " << billId << endl;
            it = services.erase(it);
            removed = true;
        } else {
            ++it;
        }
    }
    return removed;
}

bool ServiceManager::removeServicesByType(int serviceType) {
    auto it = services.begin();
    bool removed = false;
    while (it != services.end()) {
        if (it->getServiceType() == serviceType) {
            cout << "- Removed service ID " << it->getServiceId() << " of type " << serviceType << endl;
            it = services.erase(it);
            removed = true;
        } else {
            ++it;
        }
    }
    return removed;
}

bool ServiceManager::updateServicePrices(int serviceType, double newPrice) {
    bool updated = false;
    for (auto& service : services) {
        if (service.getServiceType() == serviceType) {
            service.setPrice(newPrice);
            updated = true;
        }
    }
    if (updated) {
        cout << "* Updated prices for service type " << serviceType << " to " << newPrice << endl;
    }
    return updated;
}

double ServiceManager::getTotalRevenue() const {
    double total = 0.0;
    for (const auto& service : services) {
        total += service.getQuantity() * service.getPrice();
    }
    return total;
}

// Private helper methods
vector<Service>::iterator ServiceManager::findServiceIterator(int serviceId) {
    for (auto it = services.begin(); it != services.end(); ++it) {
        if (it->getServiceId() == serviceId) {
            return it;
        }
    }
    return services.end();
}

void ServiceManager::sortServicesById() {
    sort(services.begin(), services.end(),
         [](const Service& a, const Service& b) {
             return a.getServiceId() < b.getServiceId();
         });
}

bool ServiceManager::isValidServiceType(int serviceType) const {
    return serviceType >= 0 && serviceType <= 10; // Assume 0-10 are valid service types
}

bool ServiceManager::isValidQuantity(int quantity) const {
    return quantity > 0;
}

bool ServiceManager::isValidPrice(double price) const {
    return price >= 0.0;
}
