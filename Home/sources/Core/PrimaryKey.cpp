#include <Core/PrimaryKey.h>
using namespace std;

bool PrimaryKey::isKeyInUse(int key) const {
    return used_keys.find(key) != used_keys.end();
}
bool PrimaryKey::addKey(int key) {
    if (isKeyInUse(key)) {
        return false;
    }
    used_keys.insert(key);
    return true;
}
int PrimaryKey::getNextKey() {
    int new_key = generateKey();
    while (used_keys.find(new_key) != used_keys.end()) {
        new_key = generateKey();
    }
    used_keys.insert(new_key);
    return new_key;
}
void PrimaryKey::releaseKey(int key) {
    used_keys.erase(key);
}

int PrimaryKey::generateKey() {
    return currentKey++;
}