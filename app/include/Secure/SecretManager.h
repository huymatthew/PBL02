#ifndef SECURE_SECRETMANAGER_H
#define SECURE_SECRETMANAGER_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class SecretManager {
public:
    static long long passhashed;
    static string salt;
    static long long filesign;
    static void loadSecrets();
    static void saveSecrets();
private:
    SecretManager() = default;
    ~SecretManager() = default; 
};
#endif // SECURE_SECRETMANAGER_H