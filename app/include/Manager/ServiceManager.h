#ifndef SERVICE_MANAGER_H
#define SERVICE_MANAGER_H

#include <Data/Service.h>
#include <Core/PrimaryKey.h>
#include <Core/Manager.h>
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
class DataManager;

class ServiceManager : public Manager<Service> {
public:
    ServiceManager();
    ~ServiceManager();

    bool loadFromDatabase() override;
    bool saveToDatabase() override;
    
    bool add(const Service& service) override;
    bool remove(int serviceId) override;
    bool update(int serviceId, const Service& updatedService) override;
    
    Service* get(int serviceId) override;
    bool exists(int serviceId) const override;

    int getServiceCount() const;
    int getServiceCountByBill(int billId) const;
    int getServiceCountByType(int serviceType) const;
    
    double getTotalServiceCost(int billId) const;
    double getTotalServiceCostByType(int serviceType) const;
    double getAverageServiceCost() const;
    
    int getNextServiceId();
    
private:
    bool isValidServiceType(int serviceType) const;
    bool isValidQuantity(int quantity) const;
    bool isValidPrice(double price) const;

    friend class DataManager;
};

#endif // SERVICE_MANAGER_H