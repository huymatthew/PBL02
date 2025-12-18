#ifndef RENT_MANAGER_H
#define RENT_MANAGER_H

#include <QStandardItem>
#include <QStandardItemModel>

#include <Data/Rent.h>
class DataManager;


class RentManager {
public:
    RentManager();
    ~RentManager();

    void addRent(int contractId, int tenantId, bool isRepresentative);
    bool removeRent(int contractId, int tenantId);

    int getTenantIdByContract(int contractId);
    void loadFromDatabase();
    void saveToDatabase();

    bool tenantRented(int tenantId);
private:
    Vector<Rent> rents;
    bool data_loaded;

    friend class DataManager;
};


#endif // RENT_MANAGER_H