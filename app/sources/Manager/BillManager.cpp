#include <Manager/BillManager.h>
#include <Core/ExtraFormat.h>
#include <Secure/DataSign.h>
#include <QMessageBox>
#include <iostream>

using namespace std;

BillManager::BillManager() : Manager<Bill>() {}
BillManager::~BillManager() {}

bool BillManager::loadFromDatabase(bool showLog) {
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
        if (showLog) cout << "- Loaded bill ID: " << id << endl;
    }
    return true;
}

bool BillManager::saveToDatabase(bool showLog) {
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
        if (showLog) cout << "~ Saved bill ID: " << bill.getId() << endl;
    }
    return true;
}

void BillManager::quicksave() {
    saveToDatabase(false);
    DataSign::saveDataSign();
}

bool BillManager::addBill(int contractId, const string& month, double rent, double total, int status) {
    int newId = pk_manager.getNextKey();
    Bill newBill(newId, contractId, month, rent, total, status);
    return add(newBill);
}

int BillManager::getUnpaidBillCount() const {
    int count = 0;
    for (const auto& bill : items) {
        if (bill.getStatus() == 0) {
            ++count;
        }
    }
    return count;
}

bool BillManager::markBillAsPaid(int billId) {
    auto it = this->findIterator(billId);
    if (it != items.end()) {
        it->setStatus(1);
        cout << "* Marked bill ID " << billId << " as paid." << endl;
        return true;
    }
    cerr << "Bill not found to mark as paid: " << billId << endl;
    quicksave();
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

bool BillManager::markBillAsDisabled(int billId) {
    auto it = this->findIterator(billId);
    if (it != items.end()) {
        if (it->getStatus() == 1){
            cerr << "Cannot disable a paid bill: " << billId << endl;
            return false;
        }
        it->setStatus(2);
        cout << "* Marked bill ID " << billId << " as disabled." << endl;
        quicksave();
        return true;
    }
    cerr << "Bill not found to mark as disabled: " << billId << endl;
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

long BillManager::getTotalRevenue(QDate fromDate,  QDate toDate) const {
    long totalRevenue = 0;
    for (const auto& bill : items) {
        QDate billingMonth = QDate::fromString(QString::fromStdString(bill.getBillingMonth() + "-01"), "yyyy-MM-dd");
        if (bill.getStatus() == 1 && billingMonth >= fromDate && billingMonth <= toDate) {
            totalRevenue += static_cast<long>(bill.getTotalAmount());
        }
    }
    return totalRevenue;
}

bool BillManager::validateItem(const Bill& item) const {
    ostringstream err;
    if (item.getId() <= 0) {
        err << "Invalid bill ID: " << item.getId() << endl;
    }
    if (item.getContractId() <= 0) {
        err << "Invalid contract ID for bill ID: " << item.getId() << endl;
    }
    if (item.getRoomRent() < 0) {
        err << "Invalid room rent for bill ID: " << item.getId() << endl;
    }
    if (item.getTotalAmount() < 0) {
        err << "Invalid total amount for bill ID: " << item.getId() << endl;
    }
    if (item.getStatus() < 0 || item.getStatus() > 2) {
        err << "Invalid status for bill ID: " << item.getId() << endl;
    }
    if (item.getBillingMonth().length() != 7 || item.getBillingMonth()[4] != '-') {
        err << "Invalid billing month format for bill ID: " << item.getId() << endl;
    }
    if (err.str().length() > 0) {
        QMessageBox::warning(nullptr, "Invalid Bill Data", QString::fromStdString(err.str()));
        return false;
    }
    return true;
}

QStandardItemModel* BillManager::getBillsAsModel() const {
    QStandardItemModel* model = new QStandardItemModel();
    model->setColumnCount(6);
    model->setHorizontalHeaderLabels({
        "Mã Hóa Đơn",
        "Mã Hợp Đồng",
        "Tháng Thanh Toán",
        "Giá Thuê Phòng",
        "Tổng Tiền",
        "Trạng Thái"
    });

    for (const auto& bill : items) {
        QList<QStandardItem*> rowItems;
        rowItems.append(new QStandardItem(idnumber(bill.getId(), 6)));
        rowItems.append(new QStandardItem(idnumber(bill.getContractId(), 6)));

        QStandardItem* billingMonthItem = new QStandardItem(monthFormat(bill.getBillingMonth())); // str: yyyy-MM
        QDate billingMonth = QDate::fromString(QString::fromStdString(bill.getBillingMonth() + "-01"), "yyyy-MM-dd");
        billingMonthItem->setData(billingMonth.toJulianDay(), Qt::UserRole);
        rowItems.append(billingMonthItem);
        
        QStandardItem* roomRentItem = new QStandardItem(moneyFormat(bill.getRoomRent()));
        roomRentItem->setData(bill.getRoomRent(), Qt::UserRole);
        rowItems.append(roomRentItem);
        
        QStandardItem* totalAmountItem = new QStandardItem(moneyFormat(bill.getTotalAmount()));
        totalAmountItem->setData(bill.getTotalAmount(), Qt::UserRole);
        rowItems.append(totalAmountItem);
        
        QStandardItem* item = new QStandardItem();
        if (bill.getStatus() == 0){
            item->setText("Chưa thanh toán");
            item->setForeground(QBrush(Qt::red));
        }
        else if (bill.getStatus() == 1){
            item->setText("Đã thanh toán");
            item->setForeground(QBrush(Qt::darkGreen));
        }
        else{
            item->setText("Vô hiệu hóa");
            item->setForeground(QBrush(Qt::gray));
        }
        item->setData(bill.getStatus(), Qt::UserRole);
        rowItems.append(item);
        model->appendRow(rowItems);
    }
    return model;
}