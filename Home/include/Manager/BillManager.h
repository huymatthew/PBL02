#ifndef BILL_MANAGER_H
#define BILL_MANAGER_H

#include <QStandardItem>
#include <QStandardItemModel>

#include <Data/Bill.h>
#include <Core/PrimaryKey.h>
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class BillManager {
public:
    BillManager();
    ~BillManager();

    bool loadFromDatabase();
    bool saveToDatabase();
    
    bool addBill(const Bill& bill);
    bool addBill(int contractId, const string& month,
                 double rent, double total, const string& due, int status);
    bool removeBill(int billId);
    bool updateBill(int billId, const Bill& updatedBill);
    
    Bill* getBill(int billId);
    vector<Bill> getBillsByContract(int contractId);
    vector<Bill> getBillsByMonth(const string& month);
    vector<Bill> getBillsByStatus(int status);
    vector<Bill> getAllBills() const;
    
    bool billExists(int billId) const;
    int getBillCount() const;
    double getTotalAmountByContract(int contractId) const;
    double getTotalUnpaidAmount() const;
    
    bool markBillAsPaid(int billId);
    bool markBillAsUnpaid(int billId);
    
    vector<Bill> searchBills(const string& keyword);
    
    QStandardItemModel* getBillsAsModel() const;
private:
    vector<Bill> bills;
    PrimaryKey pk_manager;
    bool data_loaded;
    
    // Helper methods
    vector<Bill>::iterator findBillIterator(int billId);
    void sortBillsByDate();
};

#endif // BILL_MANAGER_H