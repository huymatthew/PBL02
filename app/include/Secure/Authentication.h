#ifndef AUTH_H
#define AUTH_H

#include <iostream>
#include <string>
#include <random>
#include <fstream>

using namespace std;

class Authentication{
private:
    long long password;
    string salt;
    int saltLength = 10;
    bool loaded;
    void _ChangePassword(string salt, long long password);
    long long Hashing(string const& s);
    void GenerateSalt();
public:
    Authentication();
    ~Authentication();
    void loadinfo();
    void saveinfo();

    bool Login(bool justCheck = false);
    void ChangePassword();
    bool Auth(){
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
};
#endif // AUTH_H