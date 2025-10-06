#include <Manager/ContractManager.h>
#include <Core/ExtraFormat.h>
using namespace std;

ContractManager::ContractManager() : pk_manager(), data_loaded(false) {}
ContractManager::~ContractManager() {}

bool ContractManager::loadFromDatabase() {
    cout << "\033[1;32m*Loading contracts from database...\033[0m" << endl;
    ifstream file("./app/database/contracts.dat");
    if (!file) {
        cerr << "Error opening file for reading." << endl;
        return false;
    }
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        int id, roomId, status;
        string  number, start, end, signedDate, notes;
        double rent, deposit;
        if (!(iss >> id >> roomId >> start >> end >> rent >> deposit >> status >> notes)) {
            cerr << "Error reading line: " << line << endl;
            continue;
        }
        if (pk_manager.isKeyInUse(id)) {
            cerr << "Duplicate contract ID found: " << id << endl;
            continue; 
        }
        contracts.emplace_back(id, roomId, start, end, rent, deposit, status, notes);
        cout << "- Loaded contract ID: " << id << endl;
    }
    return true;
}
bool ContractManager::saveToDatabase() {
    cout << "\033[1;33m*Saving contracts to database...\033[0m" << endl;
    ofstream file("./app/database/contracts.dat", ios::out | ios::trunc);
    if (!file) {
        cerr << "Error opening file for writing." << endl;
        return false;
    }
    for (const auto& contract : contracts) {
        file << contract.getContractId() << " "
             << contract.getRoomId() << " "
             << contract.getStartDate() << " "
             << contract.getEndDate() << " "
             << contract.getMonthlyRent() << " "
             << contract.getDeposit() << " "
             << contract.getStatus() << " "
             << contract.getNotes() << endl;
        cout << "~ Saved contract ID: " << contract.getContractId() << endl;
    }
    return true;
}
bool ContractManager::addContract(const Contract& contract) {
    if (pk_manager.isKeyInUse(contract.getContractId())) {
        cerr << "Contract ID already in use: " << contract.getContractId() << endl;
        return false;
    }
    contracts.push_back(contract);
    pk_manager.addKey(contract.getContractId());
    cout << "+ Added contract ID: " << contract.getContractId() << endl;
    return true;
}
bool ContractManager::addContract(const int& roomId, const string& start, const string& end,
                                  double rent, double deposit, int status, const string& notes) {
    int newId = pk_manager.getNextKey();
    Contract newContract(newId, roomId, start, end, rent, deposit, status, notes);
    return addContract(newContract);
}
bool ContractManager::removeContract(int contractId) {
    auto it = findContractIterator(contractId);
    if (it != contracts.end()) {
        pk_manager.releaseKey(contractId);
        contracts.erase(it);
        cout << "- Removed contract ID: " << contractId << endl;
        return true;
    }
    cerr << "Contract not found for removal: " << contractId << endl;
    return false;
}
bool ContractManager::updateContract(int contractId, const Contract& updatedContract) {
    auto it = findContractIterator(contractId);
    if (it != contracts.end()) {
        *it = updatedContract;
        cout << "* Updated contract ID: " << contractId << endl;
        return true;
    }
    cerr << "Contract not found for update: " << contractId << endl;
    return false;
}

Contract* ContractManager::getContract(int contractId) {
    auto it = findContractIterator(contractId);
    if (it != contracts.end()) {
        return &(*it);
    }
    return nullptr;
}
Contract* ContractManager::getActiveContractByRoom(const int& roomId) {
    for (auto it = contracts.begin(); it != contracts.end(); ++it) {
        if (it->getRoomId() == roomId && it->getStatus() == 1) {
            return &(*it);
        }
    }
    return nullptr;
}

bool ContractManager::contractExists(int contractId) const {
    return pk_manager.isKeyInUse(contractId);
}

bool ContractManager::roomHasActiveContract(const int& roomId) const {
    for (const auto& contract : contracts) {
        if (contract.getRoomId() == roomId && contract.getStatus() == 1) { // 1: active
            return true;
        }
    }
    return false;
}
int ContractManager::getContractCount() const {
    return contracts.size();
}

bool ContractManager::activateContract(int contractId) {
    auto it = findContractIterator(contractId);
    if (it != contracts.end()) {
        it->setStatus(1); // 1: active
        cout << "* Activated contract ID: " << contractId << endl;
        return true;
    }
    cerr << "Contract not found to activate: " << contractId << endl;
    return false;
}
bool ContractManager::deactivateContract(int contractId) {
    auto it = findContractIterator(contractId);
    if (it != contracts.end()) {
        it->setStatus(0); // 0: inactive
        cout << "* Deactivated contract ID: " << contractId << endl;
        return true;
    }
    cerr << "Contract not found to deactivate: " << contractId << endl;
    return false;
}
bool ContractManager::extendContract(int contractId, const string& newEndDate) {
    auto it = findContractIterator(contractId);
    if (it != contracts.end()) {
        it->setEndDate(newEndDate);
        cout << "* Extended contract ID " << contractId << " to new end date: " << newEndDate << endl;
        return true;
    }
    cerr << "Contract not found to extend: " << contractId << endl;
    return false;
}

double ContractManager::getTotalMonthlyRent() const {
    double total = 0.0;
    for (const auto& contract : contracts) {
        total += contract.getMonthlyRent();
    }
    return total;
}
double ContractManager::getTotalDeposits() const {
    double total = 0.0;
    for (const auto& contract : contracts) {
        total += contract.getDeposit();
    }
    return total;
}

QStandardItemModel* ContractManager::getContractsAsModel() const {
    QStandardItemModel* model = new QStandardItemModel();
    model->setColumnCount(8);
    model->setHorizontalHeaderLabels({
        "Mã Hợp Đồng", "Mã Phòng",  "Ngày Bắt Đầu", "Ngày Kết Thúc",
        "Giá Thuê Tháng", "Tiền Cọc", "Trạng Thái", "Ghi Chú"
    });

    for (const auto& contract : contracts) {
        QList<QStandardItem*> rowItems;
        rowItems.append(new QStandardItem(QString::number(contract.getContractId())));
        rowItems.append(new QStandardItem(QString::number(contract.getRoomId())));
        rowItems.append(new QStandardItem(QString::fromStdString(contract.getStartDate())));
        rowItems.append(new QStandardItem(QString::fromStdString(contract.getEndDate())));
        rowItems.append(new QStandardItem(moneyFormat(contract.getMonthlyRent())));
        rowItems.append(new QStandardItem(moneyFormat(contract.getDeposit())));
        rowItems.append(new QStandardItem(contract.getStatus() == 1 ? "Active" : "Inactive"));
        rowItems.append(new QStandardItem(QString::fromStdString(contract.getNotes())));

        model->appendRow(rowItems);
    }
    return model;
}

vector<Contract>::iterator ContractManager::findContractIterator(int contractId) {
    for (auto it = contracts.begin(); it != contracts.end(); ++it) {
        if (it->getContractId() == contractId) {
            return it;
        }
    }
    return contracts.end();
}