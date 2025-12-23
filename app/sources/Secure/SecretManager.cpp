#include <Secure/SecretManager.h>

long long SecretManager::passhashed = 0;
string SecretManager::salt = "";
long long SecretManager::filesign = 0;


void SecretManager::loadSecrets(){
    ifstream f("./.env");
    if (!f.is_open()){
        cout << "Can't load secrets" << endl;
        return;
    } else {
        f >> passhashed >> salt >> filesign;
    }
}
void SecretManager::saveSecrets(){
    ofstream f("./.env", ios::out | ios::trunc);
    if (!f.is_open()){
        cout << "Can't save secrets" << endl;
        return;
    } else {
        f << passhashed << " " << salt << " " << filesign << endl;
        f.flush();
    }
}