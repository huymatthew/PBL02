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

class TenantManager {
public:
    TenantManager();
    ~TenantManager();

    bool loadFromDatabase();
    bool saveToDatabase();
    
    bool addTenant(const Tenant& tenant);
    bool addTenant(const string& fullName, const string& phone,
                  const string& identityCard, const string& dateOfBirth,
                  int contractId, bool isMainTenant);
    bool removeTenant(int tenantId);
    bool updateTenant(int tenantId, const Tenant& updatedTenant);
    
    Tenant* getTenant(int tenantId);
    Tenant* getTenantByIdentityCard(const string& identityCard);
    Tenant* getTenantByPhone(const string& phone);
    vector<Tenant> getTenantsByContract(int contractId);
    Tenant* getMainTenant(int contractId);
    vector<Tenant> getAllTenants() const;
    
    bool tenantExists(int tenantId) const;
    bool identityCardExists(const string& identityCard) const;
    bool phoneExists(const string& phone) const;
    int getTenantCount() const;
    int getTenantCountByContract(int contractId) const;
    
    bool setMainTenant(int tenantId, int contractId);
    bool hasMainTenant(int contractId) const;
    vector<Tenant> getSubTenants(int contractId);
    
    vector<Tenant> searchTenants(const string& keyword);
    vector<Tenant> searchTenantsByName(const string& name);
    vector<Tenant> searchTenantsByPhone(const string& phone);
    
    bool moveTenantsToContract(const vector<int>& tenantIds, int newContractId);
    bool removeTenantsFromContract(int contractId);
        
    bool isValidIdentityCard(const string& identityCard) const;
    bool isValidPhone(const string& phone) const;
    bool isValidDateOfBirth(const string& dateOfBirth) const;

    QStandardItemModel* getTenantsAsModel() const;
    
private:
    vector<Tenant> tenants;
    bool data_loaded;
    PrimaryKey pk_manager;
    
    vector<Tenant>::iterator findTenantIterator(int tenantId);
    void sortTenantsById();
    string formatPhone(const string& phone) const;
    string formatIdentityCard(const string& identityCard) const;
};

#endif // TENANT_MANAGER_H