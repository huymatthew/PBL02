#include <QuanLy.h>
#include <iostream>
using namespace std;

// Constructor
QuanLy::QuanLy() {
    cout << "\033[1;36mQuanLy initialized.\033[0m" << endl;
    cout << "\033[1;32mLoading database...\033[0m" << endl;

    billManager = BillManager();
    contractManager = ContractManager();
    roomManager = RoomManager();
    serviceManager = ServiceManager();
    serviceTypeManager = ServiceTypeManager();
    tenantManager = TenantManager();
}

QuanLy::~QuanLy() {
    // No need to delete vectors, they are automatically managed
    cout << "\033[1;31m=== QuanLy destroying. ===\033[0m" << endl;
    billManager.saveToDatabase();
    contractManager.saveToDatabase();
    roomManager.saveToDatabase();
    serviceManager.saveToDatabase();
    serviceTypeManager.saveToDatabase();
    tenantManager.saveToDatabase();
    cout << "\033[1;31m=== QuanLy destroyed completely. ===\033[0m" << endl;

}
