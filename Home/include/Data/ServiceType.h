#ifndef SERVICE_TYPE_H
#define SERVICE_TYPE_H

#include <string>
#include <vector>
#include <Core/PrimaryKey.h>
using namespace std;

class ServiceType {
    int service_type;
    string name;
    double price;
    static PrimaryKey<int> pk_manager;
    public:
    ServiceType();
    ServiceType(int type, const string& name, double price);

    int getServiceType() const;
    void setServiceType(int type);
    string getName() const;
    void setName(const string& name);
    double getPrice() const;
    void setPrice(double price);

    static vector<ServiceType> loadFromDatabase();
    static bool saveToDatabase(const vector<ServiceType>& serviceTypes);
};

#endif // SERVICE_TYPE_H