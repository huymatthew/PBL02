#ifndef BILL_H
#define BILL_H

#include <string>
#include <vector>
#include <Core/PrimaryKey.h>
using namespace std;

class Bill {
private:
    int bill_id;
    int contract_id;   
    string billing_month;
    double room_rent;
    double total_amount;
    string due_date;
    int status; // 0: chưa thanh toán, 1: đã thanh toán
public:
    Bill();
    Bill(const Bill& other);
    Bill(int id, int contractId, const string& month,
         double rent, double total, const string& due, int status);

    int getBillId() const;
    void setBillId(int id);

    int getContractId() const;
    void setContractId(int contractId);

    string getBillingMonth() const;
    void setBillingMonth(const string& month);

    double getRoomRent() const;
    void setRoomRent(double rent);

    double getTotalAmount() const;
    void setTotalAmount(double total);

    string getDueDate() const;
    void setDueDate(const string& due);

    int getStatus() const;
    void setStatus(int status);
};

#endif
