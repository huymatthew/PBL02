#include <Manager/ContractManager.h>
#include <Core/ExtraFormat.h>
#include <Secure/DataSign.h>
#include <Manager/DataManager.h>
#include <QMessageBox>
using namespace std;

ContractManager::ContractManager() : Manager<Contract>() {}
ContractManager::~ContractManager() {}

bool ContractManager::loadFromDatabase(bool showLog) {
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
        items.emplace_back(id, roomId, start, end, rent, deposit, status, notes);
        cout << "- Loaded contract ID: " << id << endl;
    }

    // Update
    setStatusWhenDue();

    return true;
}
bool ContractManager::saveToDatabase(bool showLog) {
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
        if (showLog) cout << "~ Saved contract ID: " << contract.getId() << endl;
    }
    return true;
}
void ContractManager::quicksave() {
    saveToDatabase(false);
    DataManager::getInstance().getRentManager().saveToDatabase(false);
    DataSign::saveDataSign();
}

bool ContractManager::addContract(const int& roomId, const string& start, const string& end,
                                  double rent, double deposit, int status, const string& notes) {
    int newId = pk_manager.getNextKey();
    Contract newContract(newId, roomId, start, end, rent, deposit, status, notes);
    return add(newContract);
}

void ContractManager::setStatusWhenDue(){
    for (auto it = items.begin(); it != items.end(); ++it) {
        string endDate = it->getEndDate();
        string currentDate = QDateTime::currentDateTime().toString("yyyy-MM-dd").toStdString();
        if (currentDate > endDate && it->getStatus() == 1) { // if current date is past end date and contract is active
            it->setStatus(0); // set to inactive
            cout << "! Contract ID " << it->getId() << " has been set to inactive." << endl;
        }
    }
}

Contract* ContractManager::getActiveContractByRoom(const int& roomId){
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->getRoomId() == roomId && it->getStatus() == 1) {
            return &(*it);
        }
    }
    return nullptr;
}

bool ContractManager::roomHasActiveContract(const int& roomId) const {
    for (const auto& contract : items) {
        if (contract.getRoomId() == roomId && contract.getStatus() == 1) { // 1: active
            return true;
        }
    }
    return false;
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

void ContractManager::deactivateContract(int contractId){
    QMessageBox::StandardButton reply = QMessageBox::question(nullptr, "Xác nhận vô hiệu hóa",
        "Bạn có chắc chắn muốn vô hiệu hóa hợp đồng này không?\n"
        "Hành động này không thể hoàn tác.",
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply != QMessageBox::Yes) {
        return; 
    }

    auto it = this->findIterator(contractId);
    if (it != items.end()) {
        it->setStatus(2);
    }
}

void ContractManager::terminateContract(int contractId){
    QMessageBox::StandardButton reply = QMessageBox::question(nullptr, "Xác nhận chấm dứt",
        "Bạn có chắc chắn muốn chấm dứt hợp đồng này không?\n"
        "Hành động này không thể hoàn tác.",
        QMessageBox::Yes | QMessageBox::No,
        QMessageBox::No);
    
    if (reply != QMessageBox::Yes) {
        return; 
    }
    
    auto it = this->findIterator(contractId);
    if (it != items.end()) {
        if (it->getStatus() != 1) {
            QMessageBox::warning(nullptr, "Chấm dứt thất bại",
                "Chỉ hợp đồng đang hoạt động mới có thể chấm dứt.");
            return;
        }
        it->setStatus(0);
    }
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


        QStandardItem* startDateItem = new QStandardItem(QString::fromStdString(contract.getStartDate()));
        QDate startDate = QDate::fromString(QString::fromStdString(contract.getStartDate()), "yyyy-MM-dd");
        startDateItem->setData(startDate.toJulianDay(), Qt::UserRole);
        rowItems.append(startDateItem);

        QStandardItem* endDateItem = new QStandardItem(QString::fromStdString(contract.getEndDate()));
        QDate endDate = QDate::fromString(QString::fromStdString(contract.getEndDate()), "yyyy-MM-dd");
        endDateItem->setData(endDate.toJulianDay(), Qt::UserRole);
        rowItems.append(endDateItem);

        QStandardItem* monthlyRentItem = new QStandardItem(moneyFormat(contract.getMonthlyRent()));
        monthlyRentItem->setData(contract.getMonthlyRent(), Qt::UserRole);
        rowItems.append(monthlyRentItem);

        QStandardItem* depositItem = new QStandardItem(moneyFormat(contract.getDeposit()));
        depositItem->setData(contract.getDeposit(), Qt::UserRole);
        rowItems.append(depositItem);

        QStandardItem* item = new QStandardItem();
        if (contract.getStatus() == 0){
            item->setText("Hết hiệu lực");
            item->setForeground(QBrush(Qt::red));
        }
        else if(contract.getStatus() == 1){
            item->setText("Còn hiệu lực");
            item->setForeground(QBrush(Qt::darkGreen));
        }
        else if(contract.getStatus() == 2){
            item->setText("Vô hiệu hóa");
            item->setForeground(QBrush(Qt::gray));
        }

        item->setData(contract.getStatus(), Qt::UserRole);
        rowItems.append(item);
        rowItems.append(new QStandardItem(QString::fromStdString(formatSpace(contract.getNotes()))));

        model->appendRow(rowItems);
    }
    return model;
}

