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
using namespace std;

class ServiceTypeManager {
public:
    ServiceTypeManager();
    ~ServiceTypeManager();

    // Database operations
    bool loadFromDatabase();
    bool saveToDatabase();
    
    // CRUD operations
    bool addServiceType(const ServiceType& serviceType);
    bool addServiceType(int serviceType, const string& name, double price);
    bool removeServiceType(int serviceType);
    bool updateServiceType(int serviceType, const ServiceType& updatedServiceType);
    
    // Query operations
    ServiceType* getServiceType(int serviceType);
    ServiceType* getServiceTypeByName(const string& name);
    vector<ServiceType> getAllServiceTypes() const;
    
    // Utility operations
    bool serviceTypeExists(int serviceType) const;
    bool serviceTypeNameExists(const string& name) const;
    int getServiceTypeCount() const;
    
    // Price operations
    bool updateServiceTypePrice(int serviceType, double newPrice);
    double getServiceTypePrice(int serviceType) const;
    string getServiceTypeName(int serviceType) const;
    
    // Search operations
    vector<ServiceType> searchServiceTypes(const string& keyword);
    vector<ServiceType> getServiceTypesByPriceRange(double minPrice, double maxPrice) const;
    
    // Sorting operations
    vector<ServiceType> getServiceTypesSortedByPrice(bool ascending = true) const;
    vector<ServiceType> getServiceTypesSortedByName() const;
    vector<ServiceType> getServiceTypesSortedById() const;
    
    // Analysis operations
    double getMaxPrice() const;
    double getMinPrice() const;
    double getAveragePrice() const;
    double getTotalPriceSum() const;
    
    // Validation operations
    bool isValidServiceTypeName(const string& name) const;
    bool isValidPrice(double price) const;
    
    // Utility methods
    vector<int> getAllServiceTypeIds() const;
    vector<string> getAllServiceTypeNames() const;
    vector<double> getAllServiceTypePrices() const;
    
    // Default service types
    bool initializeDefaultServiceTypes();
    bool addDefaultServiceType(const string& name, double defaultPrice);
    
private:
    vector<ServiceType> serviceTypes;
    bool data_loaded;
    PrimaryKey<int> pk_manager;
    
    // Helper methods
    vector<ServiceType>::iterator findServiceTypeIterator(int serviceType);
    void sortServiceTypesById();
    string trimString(const string& str) const;
    bool isStringEmpty(const string& str) const;
    
    // Default service type constants
    static const vector<pair<string, double>> DEFAULT_SERVICE_TYPES;
};

#endif // SERVICE_TYPE_MANAGER_H