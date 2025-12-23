#ifndef TENANT_MANAGER_H
#define TENANT_MANAGER_H

#include <QStandardItem>
#include <QStandardItemModel>
#include <Core/ExtraFormat.h>

#include <Core/Manager.h>
#include <Data/Tenant.h>
#include <Core/PrimaryKey.h>
#include <Core/cVector.h>
#include <string>
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
class DataManager;

class TenantManager : public Manager<Tenant> {
public:
    TenantManager();
    ~TenantManager();

    bool loadFromDatabase(bool showLog = false) override;
    bool saveToDatabase(bool showLog = false) override;
    
    bool addTenant(const string& fullName, const string& phone,
                  const string& identityCard, const string& dateOfBirth, int gender);

    Tenant* getTenantByIdentityCard(const string& identityCard);
    Tenant* getTenantByPhone(const string& phone);
    Vector<Tenant> getAllTenants() const;

    QStandardItemModel* getTenantsAsModel() const;

    Tenant* getTenantSelected();
    void setTenantSelected(Tenant* tenant);

    // Validation
    bool identityCardExists(const string& identityCard) const;
    bool phoneExists(const string& phone) const;
    bool isValidIdentityCard(const string& identityCard) const;
    bool isValidPhone(const string& phone) const;
    bool isValidDateOfBirth(const string& dateOfBirth) const;
    
private:
    Tenant* selected;
    string formatPhone(const string& phone) const;
    string formatIdentityCard(const string& identityCard) const;

    friend class DataManager;
};

#endif // TENANT_MANAGER_H