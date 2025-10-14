#ifndef MANAGER_H
#define MANAGER_H

#include <QStandardItem>
#include <QStandardItemModel>
#include <Core/PrimaryKey.h>
#include <vector>

template <typename T>
class Manager {
public:
    virtual ~Manager() {};
    virtual bool loadFromDatabase() = 0;
    virtual bool saveToDatabase() = 0;
    virtual bool add(const T& item) = 0;
    virtual bool remove(int id) = 0;
    virtual bool update(int id, const T& updatedItem) = 0;
    virtual T* get(int id) = 0;
    virtual bool exists(int id) const = 0;
    virtual int getCount() const = 0;
protected:
    vector<T> items;
    bool data_loaded;
    int item_count;
    PrimaryKey pk_manager;

    typename vector<T>::iterator findIterator(int id){
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->getId() == id) {
                return it;
            }
        }
        return items.end();
    }
};

#endif // MANAGER_H