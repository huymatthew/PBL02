#ifndef SERVICE_TYPE_H
#define SERVICE_TYPE_H

#include <string>
#include <vector>
#include <PrimaryKey.h>
using namespace std;

class ServiceType {
    int service_type;
    string name;
    double price;
    static PrimaryKey<int> pk_manager;
    public:
    ServiceType() : service_type(0), name(""), price(0.0) {}
    ServiceType(int type, const string& name, double price)
        : service_type(type), name(name), price(price) {}

    int getServiceType() const { return service_type; }
    void setServiceType(int type) { service_type = type; }
    string getName() const { return name; }
    void setName(const string& name) { this->name = name; }
    double getPrice() const { return price; }
    void setPrice(double price) { this->price = price; }

    static vector<ServiceType> loadFromDatabase();
    static bool saveToDatabase(const ServiceType& serviceType);
};

#endif // SERVICE_TYPE_H