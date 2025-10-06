#ifndef PRIMARY_KEY_MANAGER_H
#define PRIMARY_KEY_MANAGER_H

#include <string>
#include <unordered_set>
#include <random>
using namespace std;

class PrimaryKey {
private:
    unordered_set<int> used_keys;
    int generateKey();
    int currentKey = 1;
public:
    bool isKeyInUse(int key) const;
    bool addKey(int key);
    int getNextKey();
    void releaseKey(int key);
};


#endif // PRIMARY_KEY_MANAGER_H