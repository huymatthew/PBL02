#include <Data/Service.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Service::Service()
    : service_id(0), service_type(0), bill_id(0), quantity(0), price(0.0) {}

Service::Service(const Service& other)
    : service_id(other.service_id),
      service_type(other.service_type),
      bill_id(other.bill_id),
      quantity(other.quantity),
      price(other.price) {}

Service::Service(int id, int type, int billId, int qty, double price)
    : service_id(id), service_type(type), bill_id(billId), quantity(qty), price(price) {}

int Service::getServiceId() const {
    return service_id;
}

void Service::setServiceId(int id) {
    service_id = id;
}

int Service::getServiceType() const {
    return service_type;
}

void Service::setServiceType(int type) {
    service_type = type;
}

int Service::getBillId() const {
    return bill_id;
}

void Service::setBillId(int billId) {
    bill_id = billId;
}

int Service::getQuantity() const {
    return quantity;
}

void Service::setQuantity(int qty) {
    quantity = qty;
}

double Service::getPrice() const {
    return price;
}

void Service::setPrice(double p) {
    price = p;
}

