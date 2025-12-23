#include <Manager/TenantManager.h>
#include <algorithm>
#include <QMessageBox>

using namespace std;

TenantManager::TenantManager() : Manager<Tenant>() {}
TenantManager::~TenantManager() {}

bool TenantManager::loadFromDatabase(bool showLog) {
    cout << "\033[1;32m*Loading tenants from database...\033[0m" << endl;
    ifstream file("./app/database/tenants.dat");
    if (!file) {
        cerr << "Error opening file for reading." << endl;
        return false;
    }
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        int tenantId, gender;
        string fullName, phone, identityCard, dateOfBirth;
        if (!(iss >> tenantId >> fullName >> phone >> identityCard >> dateOfBirth >> gender)) {
            cerr << "Error reading line: " << line << endl;
            continue; 
        }
        if (pk_manager.isKeyInUse(tenantId)) {
            cerr << "Duplicate tenant ID found: " << tenantId << endl;
            continue; 
        }
        items.emplace_back(tenantId, fullName, phone, identityCard, dateOfBirth, gender);
        pk_manager.addKey(tenantId);
        if (showLog) cout << "- Loaded tenant ID: " << tenantId << endl;
    }
    data_loaded = true;
    return true;
}
bool TenantManager::saveToDatabase(bool showLog) {
    cout << "\033[1;33m*Saving tenants to database...\033[0m" << endl;
    ofstream file("./app/database/tenants.dat", ios::out | ios::trunc);
    if (!file) {
        cerr << "Error opening file for writing." << endl;
        return false;
    }
    for (const auto& tenant : items) {
        file << tenant.getId() << " "
             << tenant.getFullName() << " "
             << tenant.getPhone() << " "
             << tenant.getIdentityCard() << " "
             << tenant.getDateOfBirth() << " "
             << tenant.getGender() << endl;
        if (showLog) cout << "~ Saved tenant ID: " << tenant.getId() << endl;
    }
    return true;
}
void TenantManager::quicksave() {
    saveToDatabase(false);
    DataSign::saveDataSign();
}

bool TenantManager::addTenant(const string& fullName, const string& phone, const string& identityCard, const string& dateOfBirth, int gender) {
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
    Tenant newTenant(newTenantId, fullName, phone, identityCard, dateOfBirth, gender);
    return add(newTenant);
}

Tenant* TenantManager::getTenantByIdentityCard(const string& identityCard) {
    for (auto& tenant : items) {
        if (tenant.getIdentityCard() == identityCard) {
            return &tenant;
        }
    }
    return nullptr;
}
Tenant* TenantManager::getTenantByPhone(const string& phone) {
    for (auto& tenant : items) {
        if (tenant.getPhone() == phone) {
            return &tenant;
        }
    }
    return nullptr;
}
Vector<Tenant> TenantManager::getAllTenants() const {
    return items;
}

bool TenantManager::identityCardExists(const string& identityCard) const {
    for (const auto& tenant : items) {
        if (tenant.getIdentityCard() == identityCard) {
            return true;
        }
    }
    return false;
}
bool TenantManager::phoneExists(const string& phone) const {
    for (const auto& tenant : items) {
        if (tenant.getPhone() == phone) {
            return true;
        }
    }
    return false;
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
    model->setHorizontalHeaderLabels({"Mã Khách", "Họ Tên", "Giới Tính", "Số Điện Thoại", "CMND/CCCD", "Ngày Sinh"});
    
    for (const auto& tenant : items) {
        QList<QStandardItem*> row;
        row.append(new QStandardItem(idnumber(tenant.getId(), 6)));
        row.append(new QStandardItem(QString::fromStdString(formatSpace(tenant.getFullName()))));
        row.append(new QStandardItem(QString::fromStdString(tenant.getGenderString())));
        row.append(new QStandardItem(QString::fromStdString(tenant.getPhone())));
        row.append(new QStandardItem(QString::fromStdString(tenant.getIdentityCard())));
        row.append(new QStandardItem(QString::fromStdString(tenant.getDateOfBirth())));
        model->appendRow(row);
    }
    return model;
}

bool TenantManager::validateItem(const Tenant& item) const {
    ostringstream err;
    if (item.getId() <= 0) {
        err << "Invalid tenant ID: " << item.getId() << endl;
    }
    if (item.getFullName().empty()) {
        err << "Tenant name cannot be empty for tenant ID: " << item.getId() << endl;
    }
    if (!isValidPhone(item.getPhone())) {
        err << "Invalid phone number for tenant ID: " << item.getId() << endl;
    }
    if (!isValidIdentityCard(item.getIdentityCard())) {
        err << "Invalid identity card for tenant ID: " << item.getId() << endl;
    }
    if (!isValidDateOfBirth(item.getDateOfBirth())) {
        err << "Invalid date of birth for tenant ID: " << item.getId() << endl;
    }
    if (item.getGender() != 1 && item.getGender() != 2) {
        err << "Invalid gender for tenant ID: " << item.getId() << endl;
    }
    if (err.str().length() > 0) {
        QMessageBox::warning(nullptr, "Dữ liệu khách thuê không hợp lệ", QString::fromStdString(err.str()));
        return false;
    }
    return true;
}
