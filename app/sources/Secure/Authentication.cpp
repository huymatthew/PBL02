#include <Secure/Authentication.h>
#include <Secure/SecretManager.h>

Authentication::Authentication() : password(738912838912), salt("126737"){
    if (!loaded) loadinfo();
}

Authentication::~Authentication(){
    if (loaded) saveinfo();
}

void Authentication::GenerateSalt(){
    string base = "0123456789abcdefghijklmnopqrstuvxwyzABCDEFGHIJKLMNOPQRSTUVXWYZ";
    for (int i = 0; i < saltLength; i++){
        salt += base[rand() % base.size()];
    }
}

long long Authentication::Hashing(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;   
}

bool Authentication::Login(bool justCheck){
    if (!loaded) return false;
    string inp;
    cout << "Please input your password: ";
    cin >> inp;
    if (Hashing(inp + salt) == password){
        if (!justCheck) cout << "LOGIN COMPLETED" << endl;
        return true;
    }
    cout << "PASSWORD ERROR" << endl;
    return false;
}
void Authentication::_ChangePassword(string salt, long long password){
    this->salt = salt;
    this->password = password;
}

void Authentication::ChangePassword(){
    if (!loaded)  return;
    if (Login(true)){
        string inp1, inp2;
        cout << "Please input new password: ";
        cin >> inp1;
        cout << "Please input again new password: ";
        cin >> inp2;
        if (inp1 == inp2){
            GenerateSalt();
            password = Hashing(inp1 + salt);
        }
        else{
            cout << "Password Not Match" << endl;
        }
    }
}

void Authentication::loadinfo(){
    SecretManager::loadSecrets();
    password = SecretManager::passhashed;
    salt = SecretManager::salt;
    loaded = true;
}

void Authentication::saveinfo(){
    SecretManager::passhashed = password;
    SecretManager::salt = salt;
    SecretManager::saveSecrets();
}

bool Authentication::Auth(){
    cout << "Choose your way: " << endl;
    cout << "1. Login" << endl;
    cout << "2. Change Password" << endl;
    cout << "3. Exit" << endl;
    int choice;
    cin >> choice;        
    if (choice == 1){
        return Login();
    }
    else if (choice == 2){
        ChangePassword();
        return false;
    }
    else{
        return false;
    }
}