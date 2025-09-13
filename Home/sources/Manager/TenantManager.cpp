#include <Manager/TenantManager.h>
#include <algorithm>

using namespace std;

TenantManager::TenantManager() : data_loaded(false), pk_manager() {
    loadFromDatabase();
}

TenantManager::~TenantManager() {
    saveToDatabase();
}

bool TenantManager::loadFromDatabase() {
    cout << "\033[1;32m*Loading tenants from database...\033[0m" << endl;
    ifstream file("C:\\Qt\\Project\\FirstProject\\Home\\database\\tenants.dat");
    if (!file) {
        cerr << "Error opening file for reading." << endl;
        return false;
    }
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        int tenantId, contractId, isMainTenant;
        string fullName, phone, identityCard, dateOfBirth;
        if (!(iss >> tenantId >> fullName >> phone >> identityCard >> dateOfBirth >> contractId >> isMainTenant)) {
            cerr << "Error reading line: " << line << endl;
            continue; 
        }
        if (pk_manager.isKeyInUse(tenantId)) {
            cerr << "Duplicate tenant ID found: " << tenantId << endl;
            continue; 
        }
        tenants.emplace_back(tenantId, fullName, phone, identityCard, dateOfBirth, contractId, isMainTenant);
        pk_manager.addKey(tenantId);
        cout << "- Loaded tenant ID: " << tenantId << endl;
    }
    data_loaded = true;
    return true;
}
bool TenantManager::saveToDatabase() {
    cout << "\033[1;33m*Saving tenants to database...\033[0m" << endl;
    ofstream file("C:\\Qt\\Project\\FirstProject\\Home\\database\\tenants.dat", ios::out | ios::trunc);
    if (!file) {
        cerr << "Error opening file for writing." << endl;
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
    if (phoneExists(tenant.getPhone())) {
        cerr << "Phone number already exists: " << tenant.getPhone() << endl;
        return false;
    }
    if (!isValidIdentityCard(tenant.getIdentityCard())) {
        cerr << "Invalid identity card: " << tenant.getIdentityCard() << endl;
        return false;
    }
    if (!isValidPhone(tenant.getPhone())) {
        cerr << "Invalid phone number: " << tenant.getPhone() << endl;
        return false;
    }
    if (!isValidDateOfBirth(tenant.getDateOfBirth())) {
        cerr << "Invalid date of birth: " << tenant.getDateOfBirth() << endl;
        return false;
    }
    tenants.push_back(tenant);
    pk_manager.addKey(tenant.getTenantId());
    sortTenantsById();
    cout << "+ Added tenant ID: " << tenant.getTenantId() << endl;
    return true;
}
bool TenantManager::addTenant(const string& fullName, const string& phone, const string& identityCard, const string& dateOfBirth, int contractId, bool isMainTenant) {
    int newTenantId = pk_manager.getNextKey();
    if (identityCardExists(identityCard)) {
        cerr << "Identity card already exists: " << identityCard << endl;
        return false;
    }
    if (phoneExists(phone)) {
        cerr << "Phone number already exists: " << phone << endl;
        return false;
    }
    if (!isValidIdentityCard(identityCard)) {
        cerr << "Invalid identity card: " << identityCard << endl;
        return false;
    }
    if (!isValidPhone(phone)) {
        cerr << "Invalid phone number: " << phone << endl;
        return false;
    }
    if (!isValidDateOfBirth(dateOfBirth)) {
        cerr << "Invalid date of birth: " << dateOfBirth << endl;
        return false;
    }
    Tenant newTenant(newTenantId, fullName, phone, identityCard, dateOfBirth, contractId, isMainTenant);
    tenants.push_back(newTenant);
    pk_manager.addKey(newTenantId);
    sortTenantsById();
    cout << "+ Added tenant ID: " << newTenantId << endl;
    return true;
}

bool TenantManager::removeTenant(int tenantId) {
    auto it = findTenantIterator(tenantId);
    if (it != tenants.end()) {
        pk_manager.releaseKey(tenantId);
        tenants.erase(it);
        cout << "- Removed tenant ID: " << tenantId << endl;
        return true;
    }
    cerr << "Tenant not found for removal: " << tenantId << endl;
    return false;
}
bool TenantManager::updateTenant(int tenantId, const Tenant& updatedTenant) {
    auto it = findTenantIterator(tenantId);
    if (it == tenants.end()) {
        cerr << "Tenant ID not found: " << tenantId << endl;
        return false;
    }
    if (updatedTenant.getTenantId() != tenantId && tenantExists(updatedTenant.getTenantId())) {
        cerr << "Updated tenant ID already exists: " << updatedTenant.getTenantId() << endl;
        return false;
    }
    if (updatedTenant.getIdentityCard() != it->getIdentityCard() && identityCardExists(updatedTenant.getIdentityCard())) {
        cerr << "Updated identity card already exists: " << updatedTenant.getIdentityCard() << endl;
        return false;
    }
    if (updatedTenant.getPhone() != it->getPhone() && phoneExists(updatedTenant.getPhone())) {
        cerr << "Updated phone number already exists: " << updatedTenant.getPhone() << endl;
        return false;
    }
    if (!isValidIdentityCard(updatedTenant.getIdentityCard())) {
        cerr << "Invalid identity card: " << updatedTenant.getIdentityCard() << endl;
        return false;
    }
    if (!isValidPhone(updatedTenant.getPhone())) {
        cerr << "Invalid phone number: " << updatedTenant.getPhone() << endl;
        return false;
    }
    if (!isValidDateOfBirth(updatedTenant.getDateOfBirth())) {
        cerr << "Invalid date of birth: " << updatedTenant.getDateOfBirth() << endl;
        return false;
    }
    if (updatedTenant.getTenantId() != tenantId) {
        pk_manager.releaseKey(it->getTenantId());
        pk_manager.addKey(updatedTenant.getTenantId());
    }
    *it = updatedTenant;
    sortTenantsById();
    cout << "* Updated tenant ID: " << tenantId << endl;
    return true;
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
    return pk_manager.isKeyInUse(tenantId);
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
    auto it = findTenantIterator(tenantId);
    if (it == tenants.end()) {
        cerr << "Tenant ID not found: " << tenantId << endl;
        return false;
    }
    if (it->getContractId() != contractId) {
        cerr << "Tenant does not belong to the specified contract: " << contractId << endl;
        return false;
    }
    for (auto& tenant : tenants) {
        if (tenant.getContractId() == contractId && tenant.getIsMainTenant()) {
            tenant.setIsMainTenant(false); // Unset previous main tenant
            cout << "~ Unset previous main tenant ID: " << tenant.getTenantId() << endl;
            break;
        }
    }
    it->setIsMainTenant(true);
    cout << "* Set main tenant ID: " << tenantId << " for contract ID: " << contractId << endl;
    return true;
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

bool TenantManager::moveTenantsToContract(const vector<int>& tenantIds, int newContractId) {
    for (int tenantId : tenantIds) {
        auto it = findTenantIterator(tenantId);
        if (it != tenants.end()) {
            it->setContractId(newContractId);
            cout << "* Moved tenant ID: " << tenantId << " to contract ID: " << newContractId << endl;
        } else {
            cerr << "Tenant ID not found for moving: " << tenantId << endl;
        }
    }
    return true;
}
bool TenantManager::removeTenantsFromContract(int contractId) {
    auto it = tenants.begin();
    while (it != tenants.end()) {
        if (it->getContractId() == contractId) {
            pk_manager.releaseKey(it->getTenantId());
            cout << "- Removed tenant ID: " << it->getTenantId() << " from contract ID: " << contractId << endl;
            it = tenants.erase(it);
        } else {
            ++it;
        }
    }
    return true;
}

bool TenantManager::isValidIdentityCard(const string& identityCard) const {
    if (identityCard.length() != 9 && identityCard.length() != 12) {
        return false;
    }
    for (char c : identityCard) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}
bool TenantManager::isValidPhone(const string& phone) const {
    if (phone.length() < 10 || phone.length() > 15) {
        return false;
    }
    for (char c : phone) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}
bool TenantManager::isValidDateOfBirth(const string& dateOfBirth) const {
    // yyyy-mm-dd
    if (dateOfBirth.length() != 10 || dateOfBirth[4] != '-' || dateOfBirth[7] != '-') {
        return false;
    }
    for (char c : dateOfBirth) {
        if (!isdigit(c) && c != '-') {
            return false;
        }
    }
    int year = stoi(dateOfBirth.substr(0, 4));
    int month = stoi(dateOfBirth.substr(5, 2));
    int day = stoi(dateOfBirth.substr(8, 2));
    if (month < 1 || month > 12 || day < 1) {
        return false;
    }
    static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int maxDay = daysInMonth[month - 1];
    // Check for leap year in February
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        maxDay = 29;
    }
    return day <= maxDay;
}

vector<Tenant>::iterator TenantManager::findTenantIterator(int tenantId) {
    for (auto it = tenants.begin(); it != tenants.end(); ++it) {
        if (it->getTenantId() == tenantId) {
            return it;
        }
    }
    return tenants.end();
}

void TenantManager::sortTenantsById() {
    sort(tenants.begin(), tenants.end(), [](const Tenant& a, const Tenant& b) {
        return a.getTenantId() < b.getTenantId();
    });
}

string TenantManager::formatPhone(const string& phone) const {
    string formatted = phone;
    formatted.erase(remove_if(formatted.begin(), formatted.end(), [](char c) { return !isdigit(c); }), formatted.end());
    return formatted;
}

string TenantManager::formatIdentityCard(const string& identityCard) const {
    string formatted = identityCard;
    formatted.erase(remove_if(formatted.begin(), formatted.end(), [](char c) { return !isdigit(c); }), formatted.end());
    return formatted;
}

QStandardItemModel* TenantManager::getTenantsAsModel() const {
    QStandardItemModel* model = new QStandardItemModel();
    model->setHorizontalHeaderLabels({"Mã Khách", "Họ Tên", "Số Điện Thoại", "CMND/CCCD", "Ngày Sinh"});
    
    for (const auto& tenant : tenants) {
        QList<QStandardItem*> row;
        row.append(new QStandardItem(QString::number(tenant.getTenantId())));
        row.append(new QStandardItem(QString::fromStdString(tenant.getFullName())));
        row.append(new QStandardItem(QString::fromStdString(tenant.getPhone())));
        row.append(new QStandardItem(QString::fromStdString(tenant.getIdentityCard())));
        row.append(new QStandardItem(QString::fromStdString(tenant.getDateOfBirth())));
        model->appendRow(row);
    }
    return model;
}