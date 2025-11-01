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
        string month, due;
        double rent, total;
        if (!(iss >> id >> contractId >> month >> rent >> total >> due >> status)) {
            cerr << "Error reading line: " << line << endl;
            continue;
        }
        if (pk_manager.isKeyInUse(id)) {
            cerr << "Duplicate bill ID found: " << id << endl;
            continue; 
        }
        items.emplace_back(id, contractId, month, rent, total, due, status);
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
             << bill.getDueDate() << " "
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

bool BillManager::addBill(int contractId, const string& month, double rent, double total, const string& due, int status) {
    int newId = pk_manager.getNextKey();
    Bill newBill(newId, contractId, month, rent, total, due, status);
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

QStandardItemModel* BillManager::getBillsAsModel() const {
    QStandardItemModel* model = new QStandardItemModel();
    model->setColumnCount(7);
    model->setHorizontalHeaderLabels({
        "Mã Hóa Đơn",
        "Mã Hợp Đồng",
        "Tháng Thanh Toán",
        "Giá Thuê Phòng",
        "Tổng Số Tiền",
        "Ngày Đến Hạn",
        "Trạng Thái"
    });

    for (const auto& bill : items) {
        QList<QStandardItem*> rowItems;
        rowItems.append(new QStandardItem(QString::number(bill.getId())));
        rowItems.append(new QStandardItem(QString::number(bill.getContractId())));
        rowItems.append(new QStandardItem(monthFormat(bill.getBillingMonth())));
        rowItems.append(new QStandardItem(moneyFormat(bill.getRoomRent())));
        rowItems.append(new QStandardItem(moneyFormat(bill.getTotalAmount())));
        rowItems.append(new QStandardItem(dateFormat(bill.getDueDate())));
        rowItems.append(new QStandardItem(bill.getStatus() == 1 ? "Đã thanh toán" : "Chưa thanh toán"));
        model->appendRow(rowItems);
    }
    return model;
}