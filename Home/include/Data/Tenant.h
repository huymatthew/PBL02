#ifndef TENANT_H
#define TENANT_H

#include <string>
#include <vector>
#include <Core/PrimaryKey.h>

using namespace std;
class Tenant {
private:
    int tenant_id;
    string full_name;
    string phone;
    string identity_card;
    string date_of_birth; // ddmmyyyy
    int contract_id;           // FK -> Contracts
    bool is_main_tenant;

public:
    Tenant();
    Tenant(const Tenant& other);
    Tenant(int id, const string& name, const string& phone,
           const string& id_card, const string& dob,
           int contractId, bool isMain);


    static vector<Tenant> loadFromDatabase();
    static bool saveToDatabase(const vector<Tenant>& tenants);

    // Getter - Setter
    int getTenantId() const;
    void setTenantId(int id);

    string getFullName() const;
    void setFullName(const string& name);

    string getPhone() const;
    void setPhone(const string& phone);

    string getIdentityCard() const;
    void setIdentityCard(const string& idCard);

    string getDateOfBirth() const;
    void setDateOfBirth(const string& dob);

    int getContractId() const;
    void setContractId(int contractId);

    bool getIsMainTenant() const;
    void setIsMainTenant(bool isMain);
};

#endif
