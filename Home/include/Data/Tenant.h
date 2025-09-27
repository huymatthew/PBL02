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
    int gender = 0;

    public:
    Tenant();
    Tenant(const Tenant& other);
    Tenant(int id, const string& name, const string& phone,
           const string& id_card, const string& dob, int gender);
    ~Tenant();

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

    int getGender() const;
    void setGender(int gender);
    string getGenderString() const;
};

#endif
