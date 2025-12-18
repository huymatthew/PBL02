#ifndef BILL_MANAGER_H
#define BILL_MANAGER_H

#include <Data/Bill.h>
#include <Core/Manager.h>
#include <Core/cVector.h>
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
    bool addBill(int contractId, const string& month,
             double rent, double total, int status);
    bool remove(int billId) override;
    bool update(int billId, const Bill& updatedBill) override;
    Bill* get(int billId) override;
    bool exists(int billId) const override;
    int getCount() const override;
    int getUnpaidBillCount() const;

    bool markBillAsPaid(int billId);
    bool markBillAsUnpaid(int billId);
    long getTotalPaidBillInDay(QString date) const;
    long getTotalUnpaidBillInDay(QString date) const;

    long getTotalRevenue(QDate fromDate,  QDate toDate) const;
    
    
    QStandardItemModel* getBillsAsModel() const;

    void setSelected(Bill* bill) {selected = bill;}
    Bill* getSelected() {return selected;}

private:
    Bill* selected;

    friend class DataManager;
};

#endif // BILL_MANAGER_H