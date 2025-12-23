#ifndef SERVICE_TYPE_MANAGER_H
#define SERVICE_TYPE_MANAGER_H

#include <Data/ServiceType.h>
#include <Core/PrimaryKey.h>
#include <QStringList>
#include <Core/cVector.h>
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

    bool loadFromDatabase(bool showLog = false);
    
    ServiceType* getServiceType(int serviceType);
    ServiceType* getServiceTypeByName(const string& name);
    Vector<ServiceType> getAllServiceTypes() const;
    
    bool serviceTypeExists(int serviceType) const;
    bool serviceTypeNameExists(const string& name) const;
    int getServiceTypeCount() const;
    
    double getServiceTypePrice(int serviceType) const;
    string getServiceTypeName(int serviceType) const;
    QStringList getServiceTypeNamesForComboBox() const;
    
private:
    Vector<ServiceType> serviceTypes;
    bool data_loaded;
    Vector<ServiceType>::iterator findServiceTypeIterator(int serviceType);
};

#endif // SERVICE_TYPE_MANAGER_H