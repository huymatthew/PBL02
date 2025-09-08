#include <Data/Bill.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

PrimaryKey<int> Bill::pk_manager = PrimaryKey<int>();
Bill::Bill() : bill_id(0), contract_id(0), billing_month(""), room_rent(0.0),
               total_amount(0.0), due_date(""), status(0) {}
Bill::Bill(const Bill& other)
    : bill_id(other.bill_id), contract_id(other.contract_id), billing_month(other.billing_month),
      room_rent(other.room_rent), total_amount(other.total_amount),
      due_date(other.due_date), status(other.status) {}
Bill::Bill(int id, int contractId, const string& month,
                double rent, double total, const string& due, int status)
     : bill_id(id), contract_id(contractId), billing_month(month),
        room_rent(rent), total_amount(total), due_date(due), status(status) {}

// Getter - Setter
int Bill::getBillId() const {
    return bill_id;
}
void Bill::setBillId(int id) {
    bill_id = id;
}

int Bill::getContractId() const {
    return contract_id;
}
void Bill::setContractId(int contractId) {
    contract_id = contractId;
}

string Bill::getBillingMonth() const {
    return billing_month;
}
void Bill::setBillingMonth(const string& month) {
    billing_month = month;
}

double Bill::getRoomRent() const {
    return room_rent;
}
void Bill::setRoomRent(double rent) {
    room_rent = rent;
}

double Bill::getTotalAmount() const {
    return total_amount;
}
void Bill::setTotalAmount(double total) {
    total_amount = total;
}

string Bill::getDueDate() const {
    return due_date;
}
void Bill::setDueDate(const string& due) {
    due_date = due;
}

int Bill::getStatus() const {
    return status;
}
void Bill::setStatus(int status) {
    this->status = status;
}

vector<Bill> Bill::loadFromDatabase() {
    vector<Bill> bills;
    cout << "\033[1;32m*Loading bills from database...\033[0m" << endl;
    ifstream file("C:\\Qt\\Project\\FirstProject\\Home\\database\\bills.dat");
    if (!file) {
        cerr << "Error opening file for reading." << endl;
        return bills;
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
    return bills;
}

bool Bill::saveToDatabase(const vector<Bill>& bills) {
    cout << "\033[1;33m*Saving bills to database...\033[0m" << endl;
    ofstream file("C:\\Qt\\Project\\FirstProject\\Home\\database\\bills.dat", ios::app);
    if (!file) {
        cerr << "Error opening file for writing." << endl;
        return false;
    }
    for (const auto& bill : bills) {
        file << bill.bill_id << " "
             << bill.contract_id << " "
             << bill.billing_month << " "
             << bill.room_rent << " "
             << bill.total_amount << " "
             << bill.due_date << " "
             << bill.status << endl;
        cout << "~ Saved bill ID: " << bill.bill_id << endl;
    }
    return true;
}
