#include <Manager/TenantManager.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
using namespace std;

TenantManager::TenantManager() : data_loaded(false) {}

TenantManager::~TenantManager() {}

bool TenantManager::loadFromDatabase() {
    cout << "\033[1;32m*Loading tenants from database...\033[0m" << endl;
    ifstream file("C:\\Qt\\Project\\FirstProject\\Home\\database\\tenants.dat");
    if (!file) {
        cerr << "Error opening tenants.dat for reading." << endl;
        return false;
    }
    
    tenants.clear();
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        int tenantId, contractId;
        bool isMainTenant;
        string fullName, phone, identityCard, dateOfBirth;
        
        if (!(iss >> tenantId >> fullName >> phone >> identityCard >> dateOfBirth >> contractId >> isMainTenant)) {
            cerr << "Error reading line: " << line << endl;
            continue;
        }
        
        Tenant tenant(tenantId, fullName, phone, identityCard, dateOfBirth, contractId, isMainTenant);
        tenants.push_back(tenant);
        cout << "- Loaded tenant ID: " << tenantId << endl;
    }
    
    data_loaded = true;
    return true;
}

bool TenantManager::saveToDatabase() {
    cout << "\033[1;33m*Saving tenants to database...\033[0m" << endl;
    ofstream file("C:\\Qt\\Project\\FirstProject\\Home\\database\\tenants.dat", ios::out | ios::trunc);
    if (!file) {
        cerr << "Error opening tenants.dat for writing." << endl;
        return false;
    }
    
    for (const auto& tenant : tenants) {
        file << tenant.getTenantId() << " "
             << tenant.getFullName() << " "
             << tenant.getPhone() << " "
             << tenant.getIdentityCard() << " "
             << tenant.getDateOfBirth() << " "
             << tenant.getContractId() << " "
             << tenant.getIsMainTenant() << endl;
        cout << "~ Saved tenant ID: " << tenant.getTenantId() << endl;
    }
    
    return true;
}

bool TenantManager::addTenant(const Tenant& tenant) {
    if (tenantExists(tenant.getTenantId())) {
        cerr << "Tenant ID already exists: " << tenant.getTenantId() << endl;
        return false;
    }
    
    if (identityCardExists(tenant.getIdentityCard())) {
        cerr << "Identity card already exists: " << tenant.getIdentityCard() << endl;
        return false;
    }
    
    tenants.push_back(tenant);
    cout << "+ Added tenant ID: " << tenant.getTenantId() << endl;
    return true;
}

bool TenantManager::addTenant(const string& fullName, const string& phone,
                            const string& identityCard, const string& dateOfBirth,
                            int contractId, bool isMainTenant) {
    // Generate new ID
    int newId = tenants.empty() ? 1 : tenants.back().getTenantId() + 1;
    Tenant newTenant(newId, fullName, phone, identityCard, dateOfBirth, contractId, isMainTenant);
    return addTenant(newTenant);
}

bool TenantManager::removeTenant(int tenantId) {
    auto it = findTenantIterator(tenantId);
    if (it != tenants.end()) {
        tenants.erase(it);
        cout << "- Removed tenant ID: " << tenantId << endl;
        return true;
    }
    cerr << "Tenant not found for removal: " << tenantId << endl;
    return false;
}

bool TenantManager::updateTenant(int tenantId, const Tenant& updatedTenant) {
    auto it = findTenantIterator(tenantId);
    if (it != tenants.end()) {
        *it = updatedTenant;
        cout << "* Updated tenant ID: " << tenantId << endl;
        return true;
    }
    cerr << "Tenant not found for update: " << tenantId << endl;
    return false;
}

Tenant* TenantManager::getTenant(int tenantId) {
    auto it = findTenantIterator(tenantId);
    if (it != tenants.end()) {
        return &(*it);
    }
    return nullptr;
}

Tenant* TenantManager::getTenantByIdentityCard(const string& identityCard) {
    for (auto& tenant : tenants) {
        if (tenant.getIdentityCard() == identityCard) {
            return &tenant;
        }
    }
    return nullptr;
}

Tenant* TenantManager::getTenantByPhone(const string& phone) {
    for (auto& tenant : tenants) {
        if (tenant.getPhone() == phone) {
            return &tenant;
        }
    }
    return nullptr;
}

vector<Tenant> TenantManager::getTenantsByContract(int contractId) {
    vector<Tenant> result;
    for (const auto& tenant : tenants) {
        if (tenant.getContractId() == contractId) {
            result.push_back(tenant);
        }
    }
    return result;
}

Tenant* TenantManager::getMainTenant(int contractId) {
    for (auto& tenant : tenants) {
        if (tenant.getContractId() == contractId && tenant.getIsMainTenant()) {
            return &tenant;
        }
    }
    return nullptr;
}

vector<Tenant> TenantManager::getAllTenants() const {
    return tenants;
}

bool TenantManager::tenantExists(int tenantId) const {
    for (const auto& tenant : tenants) {
        if (tenant.getTenantId() == tenantId) {
            return true;
        }
    }
    return false;
}

bool TenantManager::identityCardExists(const string& identityCard) const {
    for (const auto& tenant : tenants) {
        if (tenant.getIdentityCard() == identityCard) {
            return true;
        }
    }
    return false;
}

bool TenantManager::phoneExists(const string& phone) const {
    for (const auto& tenant : tenants) {
        if (tenant.getPhone() == phone) {
            return true;
        }
    }
    return false;
}

int TenantManager::getTenantCount() const {
    return tenants.size();
}

int TenantManager::getTenantCountByContract(int contractId) const {
    int count = 0;
    for (const auto& tenant : tenants) {
        if (tenant.getContractId() == contractId) {
            count++;
        }
    }
    return count;
}

bool TenantManager::setMainTenant(int tenantId, int contractId) {
    // First, remove main tenant status from all tenants in this contract
    for (auto& tenant : tenants) {
        if (tenant.getContractId() == contractId) {
            tenant.setIsMainTenant(false);
        }
    }
    
    // Then set the specified tenant as main tenant
    auto it = findTenantIterator(tenantId);
    if (it != tenants.end() && it->getContractId() == contractId) {
        it->setIsMainTenant(true);
        cout << "* Set tenant ID " << tenantId << " as main tenant for contract " << contractId << endl;
        return true;
    }
    return false;
}

bool TenantManager::hasMainTenant(int contractId) const {
    for (const auto& tenant : tenants) {
        if (tenant.getContractId() == contractId && tenant.getIsMainTenant()) {
            return true;
        }
    }
    return false;
}

vector<Tenant> TenantManager::getSubTenants(int contractId) {
    vector<Tenant> result;
    for (const auto& tenant : tenants) {
        if (tenant.getContractId() == contractId && !tenant.getIsMainTenant()) {
            result.push_back(tenant);
        }
    }
    return result;
}

vector<Tenant> TenantManager::searchTenants(const string& keyword) {
    vector<Tenant> result;
    for (const auto& tenant : tenants) {
        if (tenant.getFullName().find(keyword) != string::npos ||
            tenant.getPhone().find(keyword) != string::npos ||
            tenant.getIdentityCard().find(keyword) != string::npos) {
            result.push_back(tenant);
        }
    }
    return result;
}

vector<Tenant> TenantManager::searchTenantsByName(const string& name) {
    vector<Tenant> result;
    for (const auto& tenant : tenants) {
        if (tenant.getFullName().find(name) != string::npos) {
            result.push_back(tenant);
        }
    }
    return result;
}

vector<Tenant> TenantManager::searchTenantsByPhone(const string& phone) {
    vector<Tenant> result;
    for (const auto& tenant : tenants) {
        if (tenant.getPhone().find(phone) != string::npos) {
            result.push_back(tenant);
        }
    }
    return result;
}

bool TenantManager::moveTenantsToContract(const vector<int>& tenantIds, int newContractId) {
    bool success = true;
    for (int tenantId : tenantIds) {
        auto it = findTenantIterator(tenantId);
        if (it != tenants.end()) {
            it->setContractId(newContractId);
            it->setIsMainTenant(false); // Reset main tenant status
            cout << "* Moved tenant ID " << tenantId << " to contract " << newContractId << endl;
        } else {
            success = false;
        }
    }
    return success;
}

bool TenantManager::removeTenantsFromContract(int contractId) {
    auto it = tenants.begin();
    bool removed = false;
    while (it != tenants.end()) {
        if (it->getContractId() == contractId) {
            cout << "- Removed tenant ID " << it->getTenantId() << " from contract " << contractId << endl;
            it = tenants.erase(it);
            removed = true;
        } else {
            ++it;
        }
    }
    return removed;
}

vector<Tenant> TenantManager::getTenantsByAgeRange(int minAge, int maxAge) const {
    vector<Tenant> result;
    for (const auto& tenant : tenants) {
        int age = calculateAge(tenant.getDateOfBirth());
        if (age >= minAge && age <= maxAge) {
            result.push_back(tenant);
        }
    }
    return result;
}

int TenantManager::calculateAge(const string& dateOfBirth) const {
    // Simple age calculation (assumes format: ddmmyyyy)
    // Extract year from dateOfBirth
    if (dateOfBirth.length() >= 8) {
        int birthYear = stoi(dateOfBirth.substr(4, 4));
        return 2025 - birthYear; // Current year is 2025
    }
    return 0;
}

bool TenantManager::isValidIdentityCard(const string& identityCard) const {
    // Check if identity card has valid format (9 or 12 digits)
    regex pattern("^[0-9]{9}$|^[0-9]{12}$");
    return regex_match(identityCard, pattern);
}

bool TenantManager::isValidPhone(const string& phone) const {
    // Check if phone number has valid format (10-11 digits, starts with 0)
    regex pattern("^0[0-9]{9,10}$");
    return regex_match(phone, pattern);
}

bool TenantManager::isValidDateOfBirth(const string& dateOfBirth) const {
    // Check if date has format ddmmyyyy
    regex pattern("^[0-3][0-9][0-1][0-9][0-9]{4}$");
    return regex_match(dateOfBirth, pattern);
}

// Private helper methods
vector<Tenant>::iterator TenantManager::findTenantIterator(int tenantId) {
    for (auto it = tenants.begin(); it != tenants.end(); ++it) {
        if (it->getTenantId() == tenantId) {
            return it;
        }
    }
    return tenants.end();
}

void TenantManager::sortTenantsById() {
    sort(tenants.begin(), tenants.end(),
         [](const Tenant& a, const Tenant& b) {
             return a.getTenantId() < b.getTenantId();
         });
}

string TenantManager::formatPhone(const string& phone) const {
    // Remove spaces and special characters
    string formatted = phone;
    formatted.erase(remove_if(formatted.begin(), formatted.end(),
                             [](char c) { return !isdigit(c); }),
                   formatted.end());
    return formatted;
}

string TenantManager::formatIdentityCard(const string& identityCard) const {
    // Remove spaces and special characters
    string formatted = identityCard;
    formatted.erase(remove_if(formatted.begin(), formatted.end(),
                             [](char c) { return !isdigit(c); }),
                   formatted.end());
    return formatted;
}
