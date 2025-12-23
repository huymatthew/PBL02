#ifndef SERVICE_MANAGER_H
#define SERVICE_MANAGER_H

#include <Data/Service.h>
#include <Core/PrimaryKey.h>
#include <Core/Manager.h>
#include <Core/cVector.h>
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

    bool loadFromDatabase(bool showLog = false) override;
    bool saveToDatabase(bool showLog = false) override;
    void quicksave() override;
    
    bool addService(int serviceType, int billId, int quantity, double price);

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