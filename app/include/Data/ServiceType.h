#ifndef SERVICE_TYPE_H
#define SERVICE_TYPE_H

#include <string>
#include <Core/cVector.h>
#include <Core/PrimaryKey.h>
using namespace std;

class ServiceType {
    int service_type;
    string name;
    double price;
    string unit;
    public:
    ServiceType();
    ServiceType(const ServiceType& other);
    ServiceType(int type, const string& name, double price, const string& unit);
    ~ServiceType();

    int getServiceType() const;
    string getName() const;
    double getPrice() const;
    string getUnit() const;
};

#endif // SERVICE_TYPE_H