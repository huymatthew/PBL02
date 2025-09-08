#include <Data/ServiceType.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

PrimaryKey<int> ServiceType::pk_manager = PrimaryKey<int>();

// Dummy implementations for demonstration purposes
ServiceType::ServiceType()
    : service_type(0), name(""), price(0.0) {}

ServiceType::ServiceType(int type, const string& name, double price)
    : service_type(type), name(name), price(price) {}

int ServiceType::getServiceType() const { return service_type; }
void ServiceType::setServiceType(int type) { service_type = type; }
string ServiceType::getName() const { return name; }
void ServiceType::setName(const string& name) { this->name = name; }
double ServiceType::getPrice() const { return price; }
void ServiceType::setPrice(double price) { this->price = price; }

vector<ServiceType> ServiceType::loadFromDatabase() {
    vector<ServiceType> serviceTypes;
    cout << "\033[1;32m*Loading service types from database...\033[0m" << endl;
    ifstream file("C:\\Qt\\Project\\FirstProject\\Home\\database\\service_types.dat");
    if (!file) {
        cerr << "Error opening service types file for reading." << endl;
        return serviceTypes;
    }
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        int serviceType;
        string name;
        double price;
        
        if (!(iss >> serviceType >> name >> price)) {
            cerr << "Error reading service type line: " << line << endl;
            continue;
        }
        if (pk_manager.isKeyInUse(serviceType)) {
            cerr << "Duplicate service type ID found: " << serviceType << endl;
            continue;
        }
        serviceTypes.emplace_back(serviceType, name, price);
        cout << "- Loaded service type ID: " << serviceType << endl;
    }
    return serviceTypes;
}

bool ServiceType::saveToDatabase(const vector<ServiceType>& serviceTypes) {
    cout << "\033[1;33m*Saving service type to database...\033[0m" << endl;
    ofstream file("C:\\Qt\\Project\\FirstProject\\Home\\database\\service_types.dat", ios::out | ios::trunc);
    if (!file) {
        cerr << "Error opening service types file for writing." << endl;
        return false;
    }
    file.clear();
    for (const auto& serviceType : serviceTypes) {
        file << serviceType.service_type << " "
             << serviceType.name << " "
             << serviceType.price << endl;
        cout << "~ Saved service type ID: " << serviceType.service_type << endl;
    }
    return true;
}