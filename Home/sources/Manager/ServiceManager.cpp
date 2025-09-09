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
            continue; // Skip malformed lines
        }
        if (pk_manager.isKeyInUse(serviceID)) {
            cerr << "Duplicate service ID found: " << serviceID << endl;
            continue; // Skip duplicate IDs
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
bool addService(const Service& service){
    
}
