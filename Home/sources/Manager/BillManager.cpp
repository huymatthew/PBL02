#include <Manager/BillManager.h>
#include <iostream>

using namespace std;

BillManager::BillManager() : data_loaded(false) {
    loadFromDatabase();
}
BillManager::~BillManager() {
    saveToDatabase();
}

bool BillManager::loadFromDatabase() {
    cout << "\033[1;32m*Loading bills from database...\033[0m" << endl;
    ifstream file("C:\\Qt\\Project\\FirstProject\\Home\\database\\bills.dat");
    if (!file) {
        cerr << "Error opening file for reading." << endl;
        return false;
    }
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        int id, contractId, status;
        string month, due;
        double rent, total;
        if (!(iss >> id >> contractId >> month >> rent >> total >> due >> status)) {
            cerr << "Error reading line: " << line << endl;
            continue; // Skip malformed lines
        }
        if (pk_manager.isKeyInUse(id)) {
            cerr << "Duplicate bill ID found: " << id << endl;
            continue; // Skip duplicate IDs
        }
        bills.emplace_back(id, contractId, month, rent, total, due, status);
        cout << "- Loaded bill ID: " << id << endl;
    }
    return true;
}

bool BillManager::saveToDatabase() {
    cout << "\033[1;33m*Saving bills to database...\033[0m" << endl;
    ofstream file("C:\\Qt\\Project\\FirstProject\\Home\\database\\bills.dat", ios::out | ios::trunc);
    if (!file) {
        cerr << "Error opening file for writing." << endl;
        return false;
    }
    file.clear();
    for (const auto& bill : bills) {
        file << bill.getBillId() << " "
             << bill.getContractId() << " "
             << bill.getBillingMonth() << " "
             << bill.getRoomRent() << " "
             << bill.getTotalAmount() << " "
             << bill.getDueDate() << " "
             << bill.getStatus() << endl;
        cout << "~ Saved bill ID: " << bill.getBillId() << endl;
    }
    return true;
}


bool BillManager::addBill(const Bill& bill) {
    if (pk_manager.isKeyInUse(bill.getBillId())) {
        cerr << "Bill ID already in use: " << bill.getBillId() << endl;
        return false;
    }
    bills.push_back(bill);
    pk_manager.addKey(bill.getBillId());
    cout << "+ Added bill ID: " << bill.getBillId() << endl;
    return true;
}

bool BillManager::addBill(int contractId, const string& month, double rent, double total, const string& due, int status) {
    int newId = pk_manager.getNextKey();
    Bill newBill(newId, contractId, month, rent, total, due, status);
    return addBill(newBill);
}

bool BillManager::removeBill(int billId) {
    auto it = findBillIterator(billId);
    if (it != bills.end()) {
        pk_manager.releaseKey(billId);
        bills.erase(it);
        cout << "- Removed bill ID: " << billId << endl;
        return true;
    }
    cerr << "Bill not found for removal: " << billId << endl;
    return false;
}

bool BillManager::updateBill(int billId, const Bill& updatedBill) {
    auto it = findBillIterator(billId);
    if (it != bills.end()) {
        *it = updatedBill;
        cout << "* Updated bill ID: " << billId << endl;
        return true;
    }
    cerr << "Bill not found for update: " << billId << endl;
    return false;
}


Bill* BillManager::getBill(int billId) {
    auto it = findBillIterator(billId);
    if (it != bills.end()) {
        return &(*it);
    }
    return nullptr;
}

bool BillManager::billExists(int billId) const {
    return pk_manager.isKeyInUse(billId);
}

int BillManager::getBillCount() const {
    return bills.size();
}


bool BillManager::markBillAsPaid(int billId) {
    auto it = findBillIterator(billId);
    if (it != bills.end()) {
        it->setStatus(1);
        cout << "* Marked bill ID " << billId << " as paid." << endl;
        return true;
    }
    cerr << "Bill not found to mark as paid: " << billId << endl;
    return false;
}

bool BillManager::markBillAsUnpaid(int billId) {
    auto it = findBillIterator(billId);
    if (it != bills.end()) {
        it->setStatus(0);
        cout << "* Marked bill ID " << billId << " as unpaid." << endl;
        return true;
    }
    cerr << "Bill not found to mark as unpaid: " << billId << endl;
    return false;
}


vector<Bill>::iterator BillManager::findBillIterator(int billId) {
    for (auto it = bills.begin(); it != bills.end(); ++it) {
        if (it->getBillId() == billId) {
            return it;
        }
    }
    return bills.end();
}