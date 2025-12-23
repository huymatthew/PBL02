#ifndef MANAGER_H
#define MANAGER_H

#include <QStandardItem>
#include <QStandardItemModel>
#include <Core/PrimaryKey.h>
#include <Core/cVector.h>
#include <iostream>
using namespace std;

template <typename T>
class Manager {
public:
    virtual ~Manager() {};
    virtual bool loadFromDatabase(bool showLog = false) = 0;
    virtual bool saveToDatabase(bool showLog = false) = 0;

    virtual bool add(const T& item);
    virtual bool remove(int id);
    virtual bool update(int id, const T& updatedItem);
    virtual T* get(int id);
    virtual bool exists(int id) const;
    virtual int getCount() const;

    int getNextId() {
        return pk_manager.getNextKey();
    }
protected:
    Vector<T> items;
    bool data_loaded;
    int item_count;
    PrimaryKey pk_manager;

    typename Vector<T>::iterator findIterator(int id){
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->getId() == id) {
                return it;
            }
        }
        return items.end();
    }
};

template <typename T>
bool Manager<T>::add(const T& item) {
    if (exists(item.getId())) {
        cerr << "Item ID already exists: " << item.getId() << endl;
        return false;
    }
    items.push_back(item);
    pk_manager.addKey(item.getId());
    cout << "+ Added item ID: " << item.getId() << endl;
    return true;
}

#endif // MANAGER_H