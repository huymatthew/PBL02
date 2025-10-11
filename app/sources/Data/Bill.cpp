#include <Data/Bill.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Bill::Bill() : bill_id(0), contract_id(0), billing_month(""), room_rent(0.0),
               total_amount(0.0), due_date(""), status(0) {}
Bill::Bill(const Bill& other)
    : bill_id(other.bill_id), contract_id(other.contract_id), billing_month(other.billing_month),
      room_rent(other.room_rent), total_amount(other.total_amount),
      due_date(other.due_date), status(other.status) {}
Bill::Bill(int id, int contractId, const string& month,
                double rent, double total, const string& due, int status)
     : bill_id(id), contract_id(contractId), billing_month(month),
        room_rent(rent), total_amount(total), due_date(due), status(status) {}
Bill::~Bill() {}

int Bill::getId() const {
    return bill_id;
}
void Bill::setId(int id) {
    bill_id = id;
}

int Bill::getContractId() const {
    return contract_id;
}
void Bill::setContractId(int contractId) {
    contract_id = contractId;
}

string Bill::getBillingMonth() const {
    return billing_month;
}
void Bill::setBillingMonth(const string& month) {
    billing_month = month;
}

double Bill::getRoomRent() const {
    return room_rent;
}
void Bill::setRoomRent(double rent) {
    room_rent = rent;
}

double Bill::getTotalAmount() const {
    return total_amount;
}
void Bill::setTotalAmount(double total) {
    total_amount = total;
}

string Bill::getDueDate() const {
    return due_date;
}
void Bill::setDueDate(const string& due) {
    due_date = due;
}

int Bill::getStatus() const {
    return status;
}
void Bill::setStatus(int status) {
    this->status = status;
}