#include <Data/ServiceType.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

ServiceType::ServiceType()
    : service_type(0), name(""), price(0.0), unit("") {}

ServiceType::ServiceType(int type, const string& name, double price, const string& unit)
    : service_type(type), name(name), price(price), unit(unit) {}
ServiceType::ServiceType(const ServiceType& other)
    : service_type(other.service_type), name(other.name),
      price(other.price), unit(other.unit) {}
ServiceType::~ServiceType() {}

int ServiceType::getServiceType() const { return service_type; }
string ServiceType::getName() const { return name; }
double ServiceType::getPrice() const { return price; }
string ServiceType::getUnit() const { return unit; }