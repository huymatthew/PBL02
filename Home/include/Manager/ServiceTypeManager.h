#ifndef SERVICE_TYPE_MANAGER_H
#define SERVICE_TYPE_MANAGER_H

#include <Data/ServiceType.h>
#include <Core/PrimaryKey.h>
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

class ServiceTypeManager {
public:
    ServiceTypeManager();
    ~ServiceTypeManager();

    bool loadFromDatabase();
    
    ServiceType* getServiceType(int serviceType);
    ServiceType* getServiceTypeByName(const string& name);
    vector<ServiceType> getAllServiceTypes() const;
    
    bool serviceTypeExists(int serviceType) const;
    bool serviceTypeNameExists(const string& name) const;
    int getServiceTypeCount() const;
    
    double getServiceTypePrice(int serviceType) const;
    string getServiceTypeName(int serviceType) const;
    
private:
    vector<ServiceType> serviceTypes;
    bool data_loaded;
    vector<ServiceType>::iterator findServiceTypeIterator(int serviceType);
};

#endif // SERVICE_TYPE_MANAGER_H