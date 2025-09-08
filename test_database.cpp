#include <iostream>
#include <Data/Bill.h>
#include <Data/Contract.h>
#include <Data/Room.h>
#include <Data/Service.h>
#include <Data/ServiceType.h>
#include <Data/Tenant.h>
#include <QuanLy.h>

using namespace std;

int main() {
    cout << "=== Database Test Program ===" << endl;
    
    // Test individual loading
    cout << "\n--- Testing Individual Data Loading ---" << endl;
    
    auto bills = Bill::loadFromDatabase();
    cout << "Bills loaded: " << bills.size() << endl;
    
    auto contracts = Contract::loadFromDatabase();
    cout << "Contracts loaded: " << contracts.size() << endl;
    
    auto rooms = Room::loadFromDatabase();
    cout << "Rooms loaded: " << rooms.size() << endl;
    
    auto services = Service::loadFromDatabase();
    cout << "Services loaded: " << services.size() << endl;
    
    auto serviceTypes = ServiceType::loadFromDatabase();
    cout << "Service Types loaded: " << serviceTypes.size() << endl;
    
    auto tenants = Tenant::loadFromDatabase();
    cout << "Tenants loaded: " << tenants.size() << endl;
    
    // Test QuanLy class
    cout << "\n--- Testing QuanLy Class ---" << endl;
    QuanLy manager;
    
    // Test saving new data
    cout << "\n--- Testing Data Saving ---" << endl;
    Bill newBill(999, 1, "2024-09", 5000000.0, 5500000.0, "2024-10-05", 0);
    if (Bill::saveToDatabase(newBill)) {
        cout << "Successfully saved new bill!" << endl;
    }
    
    Tenant newTenant(999, "Test_User", "0999888777", "999888777", "01011990", 1, false);
    if (Tenant::saveToDatabase(newTenant)) {
        cout << "Successfully saved new tenant!" << endl;
    }
    
    cout << "\n=== Test completed ===" << endl;
    return 0;
}
