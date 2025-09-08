#include <Data/Service.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

PrimaryKey<int> Service::pk_manager = PrimaryKey<int>();

// Default constructor
Service::Service()
    : service_id(0), service_type(0), bill_id(0), quantity(0), price(0.0) {}

// Copy constructor
Service::Service(const Service& other)
    : service_id(other.service_id),
      service_type(other.service_type),
      bill_id(other.bill_id),
      quantity(other.quantity),
      price(other.price) {}

// Parameterized constructor
Service::Service(int id, int type, int billId, int qty, double price)
    : service_id(id), service_type(type), bill_id(billId), quantity(qty), price(price) {}

// Getter - Setter implementations
int Service::getServiceId() const {
    return service_id;
}

void Service::setServiceId(int id) {
    service_id = id;
}

int Service::getServiceType() const {
    return service_type;
}

void Service::setServiceType(int type) {
    service_type = type;
}

int Service::getBillId() const {
    return bill_id;
}

void Service::setBillId(int billId) {
    bill_id = billId;
}

int Service::getQuantity() const {
    return quantity;
}

void Service::setQuantity(int qty) {
    quantity = qty;
}

double Service::getPrice() const {
    return price;
}

void Service::setPrice(double p) {
    price = p;
}

// Static method stubs (implement database logic as needed)
vector<Service> Service::loadFromDatabase() {
    vector<Service> services;
    cout << "\033[1;32m*Loading services from database...\033[0m" << endl;
    ifstream file("C:\\Qt\\Project\\FirstProject\\Home\\database\\services.dat");
    if (!file) {
        cerr << "Error opening services file for reading." << endl;
        return services;
    }
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        int serviceId, serviceType, billId, quantity;
        double price;
        
        if (!(iss >> serviceId >> serviceType >> billId >> quantity >> price)) {
            cerr << "Error reading service line: " << line << endl;
            continue;
        }
        if (pk_manager.isKeyInUse(serviceId)) {
            cerr << "Duplicate service ID found: " << serviceId << endl;
            continue;
        }
        services.emplace_back(serviceId, serviceType, billId, quantity, price);
        cout << "- Loaded service ID: " << serviceId << endl;
    }
    return services;
}

bool Service::saveToDatabase(const vector<Service>& services) {
    cout << "\033[1;33m*Saving service to database...\033[0m" << endl;
    ofstream file("C:\\Qt\\Project\\FirstProject\\Home\\database\\services.dat", ios::out | ios::trunc);
    if (!file) {
        cerr << "Error opening services file for writing." << endl;
        return false;
    }
    file.clear();
    for (const auto& service : services) {
        file << service.service_id << " "
             << service.service_type << " "
             << service.bill_id << " "
             << service.quantity << " "
             << service.price << endl;
        cout << "~ Saved service ID: " << service.service_id << endl;
    }
    
    return true;
}