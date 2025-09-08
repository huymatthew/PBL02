#ifndef BILL_MANAGER_H
#define BILL_MANAGER_H

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

    // Database operations
    bool loadFromDatabase();
    bool saveToDatabase();
    
    // CRUD operations
    bool addBill(const Bill& bill);
    bool addBill(int contractId, const string& month,
                 double rent, double total, const string& due, int status);
    bool removeBill(int billId);
    bool updateBill(int billId, const Bill& updatedBill);
    
    // Query operations
    Bill* getBill(int billId);
    vector<Bill> getBillsByContract(int contractId);
    vector<Bill> getBillsByMonth(const string& month);
    vector<Bill> getBillsByStatus(int status);
    vector<Bill> getAllBills() const;
    
    // Utility operations
    bool billExists(int billId) const;
    int getBillCount() const;
    double getTotalAmountByContract(int contractId) const;
    double getTotalUnpaidAmount() const;
    
    // Status management
    bool markBillAsPaid(int billId);
    bool markBillAsUnpaid(int billId);
    
    // Search operations
    vector<Bill> searchBills(const string& keyword);
    
private:
    vector<Bill> bills;
    PrimaryKey<int> pk_manager;
    bool data_loaded;
    
    // Helper methods
    vector<Bill>::iterator findBillIterator(int billId);
    void sortBillsByDate();
};

#endif // BILL_MANAGER_H