#ifndef TENANT_MANAGER_H
#define TENANT_MANAGER_H

#include <QStandardItem>
#include <QStandardItemModel>

#include <Data/Tenant.h>
#include <Core/PrimaryKey.h>
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
class DataManager;

class TenantManager {
public:
    TenantManager();
    ~TenantManager();

    bool loadFromDatabase();
    bool saveToDatabase();
    
    bool addTenant(const Tenant& tenant);
    bool addTenant(const string& fullName, const string& phone,
                  const string& identityCard, const string& dateOfBirth, int gender);
    bool removeTenant(int tenantId);
    bool updateTenant(int tenantId, const Tenant& updatedTenant);
    
    Tenant* getTenant(int tenantId);
    Tenant* getTenantByIdentityCard(const string& identityCard);
    Tenant* getTenantByPhone(const string& phone);
    vector<Tenant> getAllTenants() const;
    
    bool tenantExists(int tenantId) const;
    bool identityCardExists(const string& identityCard) const;
    bool phoneExists(const string& phone) const;
    int getTenantCount() const;
    
    bool isValidIdentityCard(const string& identityCard) const;
    bool isValidPhone(const string& phone) const;
    bool isValidDateOfBirth(const string& dateOfBirth) const;

    QStandardItemModel* getTenantsAsModel() const;

    Tenant* getTenantSelected();
    void setTenantSelected(Tenant* tenant);
    
private:
    vector<Tenant> tenants;
    bool data_loaded;
    PrimaryKey pk_manager;
    Tenant* selected;
    
    vector<Tenant>::iterator findTenantIterator(int tenantId);
    void sortTenantsById();
    string formatPhone(const string& phone) const;
    string formatIdentityCard(const string& identityCard) const;

    friend class DataManager;
};

#endif // TENANT_MANAGER_H