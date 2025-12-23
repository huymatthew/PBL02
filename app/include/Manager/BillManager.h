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

    bool loadFromDatabase(bool showLog = false) override;
    bool saveToDatabase(bool showLog = false) override;
    void quicksave() override;
    
    bool addBill(int contractId, const string& month,
             double rent, double total, int status);

    int getUnpaidBillCount() const;

    bool markBillAsPaid(int billId);
    bool markBillAsUnpaid(int billId);
    bool markBillAsDisabled(int billId);
    long getTotalPaidBillInDay(QString date) const;
    long getTotalUnpaidBillInDay(QString date) const;

    long getTotalRevenue(QDate fromDate,  QDate toDate) const;
    
    QStandardItemModel* getBillsAsModel() const;

    bool validateItem(const Bill& item) const override;
    friend class DataManager;
};

#endif // BILL_MANAGER_H