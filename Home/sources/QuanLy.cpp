#include <QuanLy.h>
#include <iostream>
using namespace std;

// Constructor
QuanLy::QuanLy() {
    cout << "\033[1;36mQuanLy initialized.\033[0m" << endl;

    // Load all data from database
    cout << "\033[1;32mLoading database...\033[0m" << endl;
    bills = Bill::loadFromDatabase();
    contracts = Contract::loadFromDatabase();
    rooms = Room::loadFromDatabase();
    services = Service::loadFromDatabase();
    serviceTypes = ServiceType::loadFromDatabase();
    tenants = Tenant::loadFromDatabase();
}

QuanLy::~QuanLy() {
    // No need to delete vectors, they are automatically managed
    cout << "\033[1;31m=== QuanLy destroying. ===\033[0m" << endl;
    Bill::saveToDatabase(bills);
    Contract::saveToDatabase(contracts);
    Room::saveToDatabase(rooms);
    Service::saveToDatabase(services);
    ServiceType::saveToDatabase(serviceTypes);
    Tenant::saveToDatabase(tenants);
    cout << "\033[1;31m=== QuanLy destroyed completely. ===\033[0m" << endl;

}
