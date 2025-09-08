#include <Data/Tenant.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

PrimaryKey<int> Tenant::pk_manager = PrimaryKey<int>();

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

// Static methods (dummy implementations)
vector<Tenant> Tenant::loadFromDatabase() {
    vector<Tenant> tenants;
    cout << "\033[1;32m*Loading tenants from database...\033[0m" << endl;
    ifstream file("C:\\Qt\\Project\\FirstProject\\Home\\database\\tenants.dat");
    if (!file) {
        cerr << "Error opening tenants file for reading." << endl;
        return tenants;
    }
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        int tenantId, contractId, isMainTenant;
        string fullName, phone, identityCard, dateOfBirth;
        
        if (!(iss >> tenantId >> fullName >> phone >> identityCard >> dateOfBirth >> contractId >> isMainTenant)) {
            cerr << "Error reading tenant line: " << line << endl;
            continue;
        }
        if (pk_manager.isKeyInUse(tenantId)) {
            cerr << "Duplicate tenant ID found: " << tenantId << endl;
            continue;
        }
        tenants.emplace_back(tenantId, fullName, phone, identityCard, dateOfBirth, contractId, (bool)isMainTenant);
        cout << "- Loaded tenant ID: " << tenantId << endl;
    }
    return tenants;
}

bool Tenant::saveToDatabase(const vector<Tenant>& tenants) {
    cout << "\033[1;33m*Saving tenants to database...\033[0m" << endl;
    ofstream file("C:\\Qt\\Project\\FirstProject\\Home\\database\\tenants.dat", ios::app);
    if (!file) {
        cerr << "Error opening tenants file for writing." << endl;
        return false;
    }
    for (const auto& tenant : tenants) {
        file << tenant.tenant_id << " "
            << tenant.full_name << " "
            << tenant.phone << " "
            << tenant.identity_card << " "
            << tenant.date_of_birth << " "
            << tenant.contract_id << " "
            << (int)tenant.is_main_tenant << endl;
        cout << "~ Saved tenant ID: " << tenant.tenant_id << endl;
    }
    return true;
}
