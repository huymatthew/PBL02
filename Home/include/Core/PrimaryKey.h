#ifndef PRIMARY_KEY_MANAGER_H
#define PRIMARY_KEY_MANAGER_H

#include <string>
#include <unordered_set>
#include <random>
using namespace std;

template<typename T>
class PrimaryKey {
private:
    unordered_set<T> used_keys;
public:
    bool isKeyInUse(const T& key) const {
        return used_keys.find(key) != used_keys.end();
    }

    bool addKey(const T& key) {
        if (isKeyInUse(key)) {
            return false;
        }
        used_keys.insert(key);
        return true;
    }
    T getNextKey() {
        T new_key = generateKey();
        while (used_keys.find(new_key) != used_keys.end()) {
            new_key = generateKey();
        }
        used_keys.insert(new_key);
        return new_key;
    }

    void releaseKey(const T& key) {
        used_keys.erase(key);
    }

private:
    T generateKey(int start = -1) {
        if (start != -1) {
            static int counter = start;
            return T(counter++);
        }
        static unsigned int seed = 123456789;
        seed = (1103515245 * seed + 12345) & 0x7fffffff;
        return T(seed);
    }
};


#endif // PRIMARY_KEY_MANAGER_H