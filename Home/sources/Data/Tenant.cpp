#include <Data/Tenant.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// Default constructor
Tenant::Tenant()
    : tenant_id(0), full_name(""), phone(""), identity_card(""),
      date_of_birth(""), contract_id(0), is_main_tenant(false) {}

// Copy constructor
Tenant::Tenant(const Tenant& other)
    : tenant_id(other.tenant_id), full_name(other.full_name),
      phone(other.phone), identity_card(other.identity_card),
      date_of_birth(other.date_of_birth), contract_id(other.contract_id),
      is_main_tenant(other.is_main_tenant) {}

// Parameterized constructor
Tenant::Tenant(int id, const string& name, const string& phone,
               const string& id_card, const string& dob,
               int contractId, bool isMain)
    : tenant_id(id), full_name(name), phone(phone), identity_card(id_card),
      date_of_birth(dob), contract_id(contractId), is_main_tenant(isMain) {}


// Getter - Setter implementations
int Tenant::getTenantId() const {
    return tenant_id;
}

void Tenant::setTenantId(int id) {
    tenant_id = id;
}

string Tenant::getFullName() const {
    return full_name;
}

void Tenant::setFullName(const string& name) {
    full_name = name;
}

string Tenant::getPhone() const {
    return phone;
}

void Tenant::setPhone(const string& phone_) {
    phone = phone_;
}

string Tenant::getIdentityCard() const {
    return identity_card;
}

void Tenant::setIdentityCard(const string& idCard) {
    identity_card = idCard;
}

string Tenant::getDateOfBirth() const {
    return date_of_birth;
}

void Tenant::setDateOfBirth(const string& dob) {
    date_of_birth = dob;
}

int Tenant::getContractId() const {
    return contract_id;
}

void Tenant::setContractId(int contractId) {
    contract_id = contractId;
}

bool Tenant::getIsMainTenant() const {
    return is_main_tenant;
}

void Tenant::setIsMainTenant(bool isMain) {
    is_main_tenant = isMain;
}
