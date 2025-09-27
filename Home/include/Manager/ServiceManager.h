#ifndef SERVICE_MANAGER_H
#define SERVICE_MANAGER_H

#include <Data/Service.h>
#include <Core/PrimaryKey.h>
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
class DataManager;

class ServiceManager {
public:
    ServiceManager();
    ~ServiceManager();

    bool loadFromDatabase();
    bool saveToDatabase();
    
    bool addService(const Service& service);
    bool addService(int serviceType, int billId, int quantity, double price);
    bool removeService(int serviceId);
    bool updateService(int serviceId, const Service& updatedService);
    
    Service* getService(int serviceId);
    vector<Service> getServicesByBill(int billId) const;
    vector<Service> getServicesByType(int serviceType) const;
    vector<Service> getAllServices() const;
    
    bool serviceExists(int serviceId) const;
    int getServiceCount() const;
    int getServiceCountByBill(int billId) const;
    int getServiceCountByType(int serviceType) const;
    
    double getTotalServiceCost(int billId) const;
    double getTotalServiceCostByType(int serviceType) const;
    double getAverageServiceCost() const;
    
    int getTotalQuantityByType(int serviceType) const;
    int getTotalQuantityByBill(int billId) const;
    double getAverageQuantityByType(int serviceType) const;
    
    double getMaxPriceByType(int serviceType) const;
    double getMinPriceByType(int serviceType) const;
    double getAveragePriceByType(int serviceType) const;
    
    vector<Service> searchServices(const string& keyword);
    vector<Service> getServicesByPriceRange(double minPrice, double maxPrice) const;
    vector<Service> getServicesByQuantityRange(int minQuantity, int maxQuantity) const;
    
    bool addMultipleServices(const vector<Service>& services);
    bool removeServicesByBill(int billId);
    bool removeServicesByType(int serviceType);
    bool updateServicePrices(int serviceType, double newPrice);
    
    vector<pair<int, double>> getServiceCostByType() const;
    vector<pair<int, int>> getServiceQuantityByType() const;
    double getTotalRevenue() const;
    
private:
    vector<Service> services;
    bool data_loaded;
    PrimaryKey pk_manager;
    
    vector<Service>::iterator findServiceIterator(int serviceId);
    void sortServicesById();
    bool isValidServiceType(int serviceType) const;
    bool isValidQuantity(int quantity) const;
    bool isValidPrice(double price) const;

    friend class DataManager;
};

#endif // SERVICE_MANAGER_H