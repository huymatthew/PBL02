#include <Data/Contract.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

PrimaryKey<int> Contract::pk_manager = PrimaryKey<int>();

// Default constructor
Contract::Contract()
    : contract_id(0), monthly_rent(0.0), deposit(0.0), status(0) {}

Contract::Contract(const Contract& other)
    : contract_id(other.contract_id), room_id(other.room_id),
      contract_number(other.contract_number), start_date(other.start_date),
      end_date(other.end_date), monthly_rent(other.monthly_rent),
      deposit(other.deposit), status(other.status),
      signed_date(other.signed_date), notes(other.notes) {}
    
Contract::Contract(int id, const string& roomId, const string& number,
                   const string& start, const string& end,
                   double rent, double deposit, int status,
                   const string& signedDate, const string& notes)
    : contract_id(id), room_id(roomId), contract_number(number),
      start_date(start), end_date(end), monthly_rent(rent),
      deposit(deposit), status(status), signed_date(signedDate),
      notes(notes) {}

int Contract::getContractId() const { return contract_id; }
void Contract::setContractId(int id) { contract_id = id; }

string Contract::getRoomId() const { return room_id; }
void Contract::setRoomId(const string& roomId) { room_id = roomId; }

string Contract::getContractNumber() const { return contract_number; }
void Contract::setContractNumber(const string& number) { contract_number = number; }

string Contract::getStartDate() const { return start_date; }
void Contract::setStartDate(const string& start) { start_date = start; }

string Contract::getEndDate() const { return end_date; }
void Contract::setEndDate(const string& end) { end_date = end; }

double Contract::getMonthlyRent() const { return monthly_rent; }
void Contract::setMonthlyRent(double rent) { monthly_rent = rent; }

double Contract::getDeposit() const { return deposit; }
void Contract::setDeposit(double deposit) { this->deposit = deposit; }

int Contract::getStatus() const { return status; }
void Contract::setStatus(int status) { this->status = status; }

string Contract::getSignedDate() const { return signed_date; }
void Contract::setSignedDate(const string& signedDate) { signed_date = signedDate; }

string Contract::getNotes() const { return notes; }
void Contract::setNotes(const string& notes) { this->notes = notes; }

// Static stub: Load contracts from database
vector<Contract> Contract::loadFromDatabase() {
    vector<Contract> contracts;

    cout << "\033[1;32m*Loading contracts from database...\033[0m" << endl;
    ifstream file("C:\\Qt\\Project\\FirstProject\\Home\\database\\contracts.dat");
    if (!file) {
        cerr << "Error opening contracts file for reading." << endl;
        return contracts;
    }
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        int id, status;
        string roomId, contractNumber, startDate, endDate, signedDate, notes;
        double monthlyRent, deposit;
        
        if (!(iss >> id >> roomId >> contractNumber >> startDate >> endDate >> monthlyRent >> deposit >> status >> signedDate >> notes)) {
            cerr << "Error reading contract line: " << line << endl;
            continue;
        }
        if (pk_manager.isKeyInUse(id)) {
            cerr << "Duplicate contract ID found: " << id << endl;
            continue;
        }
        contracts.emplace_back(id, roomId, contractNumber, startDate, endDate, monthlyRent, deposit, status, signedDate, notes);
        cout << "- Loaded contract ID: " << id << endl;
    }
    return contracts;
}

// Static stub: Save contract to database
bool Contract::saveToDatabase(const vector<Contract>& contracts) {
    cout << "\033[1;32m*Saving contracts to database...\033[0m" << endl;
    ofstream file("C:\\Qt\\Project\\FirstProject\\Home\\database\\contracts.dat", ios::out | ios::trunc);
    if (!file) {
        cerr << "Error opening contracts file for writing." << endl;
        return false;
    }
    file.clear();
    for (const auto& contract : contracts) {
        file << contract.contract_id << " "
             << contract.room_id << " "
             << contract.contract_number << " "
             << contract.start_date << " "
             << contract.end_date << " "
             << contract.monthly_rent << " "
             << contract.deposit << " "
             << contract.status << " "
             << contract.signed_date << " "
             << contract.notes << endl;
        cout << "~ Saved contract ID: " << contract.contract_id << endl;
    }
    return true;
}
