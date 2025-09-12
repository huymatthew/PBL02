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
    
    bool addServiceType(const ServiceType& serviceType);
    bool addServiceType(int serviceType, const string& name, double price);
    bool updateServiceType(int serviceType, const ServiceType& updatedServiceType);
    
    ServiceType* getServiceType(int serviceType);
    ServiceType* getServiceTypeByName(const string& name);
    vector<ServiceType> getAllServiceTypes() const;
    
    bool serviceTypeExists(int serviceType) const;
    bool serviceTypeNameExists(const string& name) const;
    int getServiceTypeCount() const;
    
    bool updateServiceTypePrice(int serviceType, double newPrice);
    double getServiceTypePrice(int serviceType) const;
    string getServiceTypeName(int serviceType) const;
    
    vector<ServiceType> searchServiceTypes(const string& keyword);
    vector<ServiceType> getServiceTypesByPriceRange(double minPrice, double maxPrice) const;
    
    vector<ServiceType> getServiceTypesSortedByPrice(bool ascending = true) const;
    vector<ServiceType> getServiceTypesSortedByName() const;
    vector<ServiceType> getServiceTypesSortedById() const;
    
    double getMaxPrice() const;
    double getMinPrice() const;
    double getAveragePrice() const;
    double getTotalPriceSum() const;
    
    bool isValidServiceTypeName(const string& name) const;
    bool isValidPrice(double price) const;
    
    vector<int> getAllServiceTypeIds() const;
    vector<string> getAllServiceTypeNames() const;
    vector<double> getAllServiceTypePrices() const;
private:
    vector<ServiceType> serviceTypes;
    bool data_loaded;
    PrimaryKey pk_manager;
    
    vector<ServiceType>::iterator findServiceTypeIterator(int serviceType);
    void sortServiceTypesById();
    string trimString(const string& str) const;
    bool isStringEmpty(const string& str) const;
    
    static const vector<pair<string, double>> DEFAULT_SERVICE_TYPES;
};

#endif // SERVICE_TYPE_MANAGER_H