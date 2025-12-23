#include <Secure/DataSign.h>

string DataSign::x = "NONE";
string DataSign::y = "NONE";

long long DataSign::hashDataSign() {
    long long combined_hash = 0;
    combined_hash += hashFile("./app/database/bills.dat");
    combined_hash += hashFile("./app/database/contracts.dat");
    combined_hash += hashFile("./app/database/rooms.dat");
    combined_hash += hashFile("./app/database/tenants.dat");
    combined_hash += hashFile("./app/database/services.dat");
    combined_hash += hashFile("./app/database/service_types.dat");
    combined_hash += hashFile("./app/database/rents.dat");
    return combined_hash;
}

long long DataSign::hashFile(const string& filePath) {
    ifstream file(filePath, ios::binary);
    if (!file) {
        cerr << "Error opening file for hashing: " << filePath << endl;
        return 0;
    }
    
    const size_t bufferSize = 8192; 
    char buffer[bufferSize];
    long long combined_hash = 0;
    
    while (file.read(buffer, bufferSize) || file.gcount() > 0) {
        size_t bytesRead = file.gcount();
        string chunk(buffer, bytesRead);
        combined_hash += hashString(chunk);
    }
    
    return combined_hash;
}

long long DataSign::hashString(const string& str) {
    const int p = 313; 
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    
    for (char c : str) {
        hash_value = (hash_value + ((unsigned char)c + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

bool DataSign::saveDataSign() {
    long long current_hash = hashDataSign();
    cout << "Data signature hash saved: " << current_hash << endl;
    ofstream f("./.env", ios::out | ios::trunc);
    if (!f.is_open()){
        cout << "Can't save data" << endl;
        return false;
    } else {
        if (x == "NONE" || y == "NONE"){
            cerr << "DataSign variables not initialized." << endl;
            return false;
        }
        f << x << " " << y << " " << current_hash << endl;
        f.flush();
        cout << "Data signature saved successfully." << endl;
        return true;
    }
}

bool DataSign::checkModified() {
    ifstream f("./.env");
    long long sign;
    if (!f.is_open()){
        cout << "Can't load data" << endl;
        return true;
    } else {
        f >> x >> y >> sign;
        long long current_hash = hashDataSign();
        return current_hash != sign;
    }
}