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
    virtual void quicksave() = 0;

    virtual bool add(const T& item);
    virtual bool remove(int id);
    virtual bool update(int id, const T& updatedItem);
    virtual T* get(int id);
    virtual bool exists(int id) const;
    virtual int getCount() const;

    virtual bool validateItem(const T& item) const { return true; }

    int getNextId() {
        return pk_manager.getNextKey();
    }

    T* getSelectedItem() const { return selectedItem; }
    void setSelectedItem(T* item) { selectedItem = item; }

protected:
    Vector<T> items;
    bool data_loaded;
    int item_count;
    PrimaryKey pk_manager;
    T* selectedItem;

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
    if (!validateItem(item)) {
        cerr << "Item validation failed: " << item.getId() << endl;
        return false;
    }
    items.push_back(item);
    pk_manager.addKey(item.getId());
    cout << "+ Added item ID: " << item.getId() << endl;
    quicksave();
    return true;
}

template <typename T>
bool Manager<T>::remove(int id) {
    auto it = this->findIterator(id);
    if (it != items.end()) {
        pk_manager.releaseKey(id);
        items.erase(it);
        cout << "- Removed item ID: " << id << endl;
        quicksave();
        return true;
    }
    cerr << "Item not found for removal: " << id << endl;
    return false;
}

template <typename T>
bool Manager<T>::update(int id, const T& updatedItem) {
    auto it = this->findIterator(id);
    if (it == items.end()) {
        cerr << "Item ID not found: " << id << endl;
        return false;
    }
    if (!validateItem(updatedItem)) {
        cerr << "Updated item validation failed: " << updatedItem.getId() << endl;
        return false;
    }
    if (updatedItem.getId() != id && exists(updatedItem.getId())) {
        cerr << "Updated item ID already exists: " << updatedItem.getId() << endl;
        return false;
    }
    if (updatedItem.getId() != id) {
        pk_manager.releaseKey(it->getId());
        pk_manager.addKey(updatedItem.getId());
    }
    *it = updatedItem;
    cout << "* Updated item ID: " << id << endl;
    quicksave();
    return true;
}

template <typename T>
T* Manager<T>::get(int id) {
    auto it = this->findIterator(id);
    if (it != items.end()) {
        return &(*it);
    }
    return nullptr;
}

template <typename T>
bool Manager<T>::exists(int id) const {
    return pk_manager.isKeyInUse(id);
}

template <typename T>
int Manager<T>::getCount() const {
    return items.size();
}

#endif // MANAGER_H