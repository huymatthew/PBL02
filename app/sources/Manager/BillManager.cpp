#include <Manager/BillManager.h>
#include <Core/ExtraFormat.h>
#include <iostream>

using namespace std;

BillManager::BillManager() : Manager<Bill>() {}
BillManager::~BillManager() {}

bool BillManager::loadFromDatabase() {
    cout << "\033[1;32m*Loading bills from database...\033[0m" << endl;
    ifstream file("./app/database/bills.dat");
    if (!file) {
        cerr << "Error opening file for reading." << endl;
        return false;
    }
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        int id, contractId, status;
        string month;
        double rent, total;
        if (!(iss >> id >> contractId >> month >> rent >> total >> status)) {
            cerr << "Error reading line: " << line << endl;
            continue;
        }
        if (pk_manager.isKeyInUse(id)) {
            cerr << "Duplicate bill ID found: " << id << endl;
            continue; 
        }
        items.emplace_back(id, contractId, month, rent, total, status);
        cout << "- Loaded bill ID: " << id << endl;
    }
    return true;
}

bool BillManager::saveToDatabase() {
    cout << "\033[1;33m*Saving bills to database...\033[0m" << endl;
    ofstream file("./app/database/bills.dat", ios::out | ios::trunc);
    if (!file) {
        cerr << "Error opening file for writing." << endl;
        return false;
    }
    file.clear();
    for (const auto& bill : items) {
        file << bill.getId() << " "
             << bill.getContractId() << " "
             << bill.getBillingMonth() << " "
             << bill.getRoomRent() << " "
             << bill.getTotalAmount() << " "
             << bill.getStatus() << endl;
        cout << "~ Saved bill ID: " << bill.getId() << endl;
    }
    return true;
}

bool BillManager::add(const Bill& bill) {
    if (pk_manager.isKeyInUse(bill.getId())) {
        cerr << "Bill ID already in use: " << bill.getId() << endl;
        return false;
    }
    items.push_back(bill);
    pk_manager.addKey(bill.getId());
    cout << "+ Added bill ID: " << bill.getId() << endl;
    return true;
}

bool BillManager::addBill(int contractId, const string& month, double rent, double total, int status) {
    int newId = pk_manager.getNextKey();
    Bill newBill(newId, contractId, month, rent, total, status);
    return add(newBill);
}

bool BillManager::remove(int billId) {
    auto it = this->findIterator(billId);
    if (it != items.end()) {
        pk_manager.releaseKey(billId);
        items.erase(it);
        cout << "- Removed bill ID: " << billId << endl;
        return true;
    }
    cerr << "Bill not found for removal: " << billId << endl;
    return false;
}

bool BillManager::update(int billId, const Bill& updatedBill) {
    auto it = this->findIterator(billId);
    if (it != items.end()) {
        *it = updatedBill;
        cout << "* Updated bill ID: " << billId << endl;
        return true;
    }
    cerr << "Bill not found for update: " << billId << endl;
    return false;
}


Bill* BillManager::get(int billId) {
    auto it = this->findIterator(billId);
    if (it != items.end()) {
        return &(*it);
    }
    return nullptr;
}

bool BillManager::exists(int billId) const {
    return pk_manager.isKeyInUse(billId);
}

int BillManager::getCount() const {
    return items.size();
}


bool BillManager::markBillAsPaid(int billId) {
    auto it = this->findIterator(billId);
    if (it != items.end()) {
        it->setStatus(1);
        cout << "* Marked bill ID " << billId << " as paid." << endl;
        return true;
    }
    cerr << "Bill not found to mark as paid: " << billId << endl;
    return false;
}

bool BillManager::markBillAsUnpaid(int billId) {
    auto it = this->findIterator(billId);
    if (it != items.end()) {
        it->setStatus(0);
        cout << "* Marked bill ID " << billId << " as unpaid." << endl;
        return true;
    }
    cerr << "Bill not found to mark as unpaid: " << billId << endl;
    return false;
}

long BillManager::getTotalPaidBillInDay(QString date) const {
    long total = 0;
    for (const auto& bill : items) {
        if (bill.getStatus() == 1 && QString::fromStdString(bill.getBillingMonth()) == date) {
            total += static_cast<long>(bill.getTotalAmount());
        }
    }
    return total;
}

long BillManager::getTotalUnpaidBillInDay(QString date) const {
    long total = 0;
    for (const auto& bill : items) {
        if (bill.getStatus() == 0 && QString::fromStdString(bill.getBillingMonth()) == date) {
            total += static_cast<long>(bill.getTotalAmount());
        }
    }
    return total;
}

QStandardItemModel* BillManager::getBillsAsModel() const {
    QStandardItemModel* model = new QStandardItemModel();
    model->setColumnCount(6);
    model->setHorizontalHeaderLabels({
        "Mã Hóa Đơn",
        "Mã Hợp Đồng",
        "Tháng Thanh Toán",
        "Giá Thuê Phòng",
        "Ngày Đến Hạn",
        "Trạng Thái"
    });

    for (const auto& bill : items) {
        QList<QStandardItem*> rowItems;
        rowItems.append(new QStandardItem(idnumber(bill.getId(), 6)));
        rowItems.append(new QStandardItem(idnumber(bill.getContractId(), 6)));
        rowItems.append(new QStandardItem(monthFormat(bill.getBillingMonth())));
        rowItems.append(new QStandardItem(moneyFormat(bill.getRoomRent())));
        rowItems.append(new QStandardItem(moneyFormat(bill.getTotalAmount())));
        QStandardItem* item = new QStandardItem();
        if (bill.getStatus() == 1){
            item->setText("Chưa thanh toán");
            item->setForeground(QBrush(Qt::red));
        }
        else{
            item->setText("Đã thanh toán");
            item->setForeground(QBrush(Qt::darkGreen));
        }
        rowItems.append(item);
        model->appendRow(rowItems);
    }
    return model;
}