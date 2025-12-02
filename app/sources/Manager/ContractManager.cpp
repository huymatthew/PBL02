#include <Manager/ContractManager.h>
#include <Core/ExtraFormat.h>
using namespace std;

ContractManager::ContractManager() : Manager<Contract>() {}
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
        pk_manager.addKey(id);
        items.emplace_back(id, roomId, start, end, rent, deposit, status, notes);
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
    for (const auto& contract : items) {
        file << contract.getId() << " "
             << contract.getRoomId() << " "
             << contract.getStartDate() << " "
             << contract.getEndDate() << " "
             << contract.getMonthlyRent() << " "
             << contract.getDeposit() << " "
             << contract.getStatus() << " "
             << contract.getNotes() << endl;
        cout << "~ Saved contract ID: " << contract.getId() << endl;
    }
    return true;
}
bool ContractManager::add(const Contract& contract) {
    // if (pk_manager.isKeyInUse(contract.getId())) {
    //     cerr << "Contract ID already in use: " << contract.getId() << endl;
    //     return false;
    // }
    items.push_back(contract);
    pk_manager.addKey(contract.getId());
    cout << "+ Added contract ID: " << contract.getId() << endl;
    return true;
}
bool ContractManager::addContract(const int& roomId, const string& start, const string& end,
                                  double rent, double deposit, int status, const string& notes) {
    int newId = pk_manager.getNextKey();
    Contract newContract(newId, roomId, start, end, rent, deposit, status, notes);
    return add(newContract);
}
bool ContractManager::remove(int contractId) {
    auto it = this->findIterator(contractId);
    if (it != items.end()) {
        pk_manager.releaseKey(contractId);
        items.erase(it);
        cout << "- Removed contract ID: " << contractId << endl;
        return true;
    }
    cerr << "Contract not found for removal: " << contractId << endl;
    return false;
}
bool ContractManager::update(int contractId, const Contract& updatedContract) {
    auto it = this->findIterator(contractId);
    if (it != items.end()) {
        *it = updatedContract;
        cout << "* Updated contract ID: " << contractId << endl;
        return true;
    }
    cerr << "Contract not found for update: " << contractId << endl;
    return false;
}

Contract* ContractManager::get(int contractId) {
    auto it = this->findIterator(contractId);
    if (it != items.end()) {
        return &(*it);
    }
    return nullptr;
}
Contract* ContractManager::getActiveContractByRoom(const int& roomId){
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->getRoomId() == roomId && it->getStatus() == 1) {
            return &(*it);
        }
    }
    return nullptr;
}

bool ContractManager::exists(int contractId) const {
    return pk_manager.isKeyInUse(contractId);
}

bool ContractManager::roomHasActiveContract(const int& roomId) const {
    for (const auto& contract : items) {
        if (contract.getRoomId() == roomId && contract.getStatus() == 1) { // 1: active
            return true;
        }
    }
    return false;
}
int ContractManager::getCount() const {
    return items.size();
}
double ContractManager::getTotalMonthlyRent() const {
    double total = 0.0;
    for (const auto& contract : items) {
        total += contract.getMonthlyRent();
    }
    return total;
}
double ContractManager::getTotalDeposits() const {
    double total = 0.0;
    for (const auto& contract : items) {
        total += contract.getDeposit();
    }
    return total;
}

bool ContractManager::roomUsed(int roomId) const {
    for (const auto& contract : items) {
        if (contract.getRoomId() == roomId) {
            return true;
        }
    }
    return false;
}

QStandardItemModel* ContractManager::getContractsAsModel() const {
    QStandardItemModel* model = new QStandardItemModel();
    model->setColumnCount(8);
    model->setHorizontalHeaderLabels({
        "Mã Hợp Đồng", "Mã Phòng",  "Ngày Bắt Đầu", "Ngày Kết Thúc",
        "Giá Thuê Tháng", "Tiền Cọc", "Trạng Thái", "Ghi Chú"
    });

    for (const auto& contract : items) {
        QList<QStandardItem*> rowItems;
        rowItems.append(new QStandardItem(idnumber(contract.getId(), 6)));
        rowItems.append(new QStandardItem(idnumber(contract.getRoomId(), 6)));
        rowItems.append(new QStandardItem(QString::fromStdString(contract.getStartDate())));
        rowItems.append(new QStandardItem(QString::fromStdString(contract.getEndDate())));
        rowItems.append(new QStandardItem(moneyFormat(contract.getMonthlyRent())));
        rowItems.append(new QStandardItem(moneyFormat(contract.getDeposit())));
        QStandardItem* item = new QStandardItem();
        if (contract.getStatus() == 0){
            item->setText("Hết hiệu lực");
            item->setForeground(QBrush(Qt::red));
        }
        else{
            item->setText("Còn hiệu lực");
            item->setForeground(QBrush(Qt::darkGreen));
        }
        rowItems.append(item);
        rowItems.append(new QStandardItem(QString::fromStdString(contract.getNotes())));

        model->appendRow(rowItems);
    }
    return model;
}
