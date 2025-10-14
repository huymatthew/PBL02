#ifndef BILL_MANAGER_H
#define BILL_MANAGER_H

#include <Data/Bill.h>
#include <Core/Manager.h>
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
class DataManager;


class BillManager : public Manager<Bill> {
public:
    BillManager();
    ~BillManager();

    bool loadFromDatabase();
    bool saveToDatabase();
    
    bool add(const Bill& bill) override;
    bool remove(int billId) override;
    bool update(int billId, const Bill& updatedBill) override;
    Bill* get(int billId) override;
    bool exists(int billId) const override;
    int getCount() const override;

    bool markBillAsPaid(int billId);
    bool markBillAsUnpaid(int billId);
    
    QStandardItemModel* getBillsAsModel() const;
    
    friend class DataManager;
};

#endif // BILL_MANAGER_H