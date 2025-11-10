#ifndef BILL_H
#define BILL_H

#include <string>
#include <Core/cVector.h>
#include <Core/PrimaryKey.h>
using namespace std;

class Bill {
private:
    int bill_id;
    int contract_id;   
    string billing_month;
    double room_rent;
    double total_amount;
    int status; // 0: chưa thanh toán, 1: đã thanh toán
public:
    Bill();
    Bill(const Bill& other);
    Bill(int id, int contractId, const string& month,
         double rent, double total, int status);
    ~Bill();

    int getId() const;
    void setId(int id);

    int getContractId() const;
    void setContractId(int contractId);

    string getBillingMonth() const;
    void setBillingMonth(const string& month);

    double getRoomRent() const;
    void setRoomRent(double rent);

    double getTotalAmount() const;
    void setTotalAmount(double total);

    int getStatus() const;
    void setStatus(int status);
};

#endif
