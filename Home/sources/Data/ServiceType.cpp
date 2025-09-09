#include <Data/ServiceType.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// Dummy implementations for demonstration purposes
ServiceType::ServiceType()
    : service_type(0), name(""), price(0.0) {}

ServiceType::ServiceType(int type, const string& name, double price)
    : service_type(type), name(name), price(price) {}

int ServiceType::getServiceType() const { return service_type; }
void ServiceType::setServiceType(int type) { service_type = type; }
string ServiceType::getName() const { return name; }
void ServiceType::setName(const string& name) { this->name = name; }
double ServiceType::getPrice() const { return price; }
void ServiceType::setPrice(double price) { this->price = price; }
