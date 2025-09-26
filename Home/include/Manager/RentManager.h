#ifndef RENT_MANAGER_H
#define RENT_MANAGER_H

#include <QStandardItem>
#include <QStandardItemModel>

#include <Data/Rent.h>

class RentManager {
public:
    RentManager();
    ~RentManager();

    int getTenantIdByContract(int contractId);
    int getRoomIdByTenant(int tenantId);
private:
    vector<Rent> rents;
    bool data_loaded;
};


#endif // RENT_MANAGER_H