#ifndef MANAGER_H
#define MANAGER_H

#include <QStandardItem>
#include <QStandardItemModel>
#include <Core/PrimaryKey.h>
#include <vector>

template <typename T>
class Manager {
public:
    virtual ~Manager();
    virtual bool loadFromDatabase();
    virtual bool saveToDatabase();
    virtual bool add(const T& item);
    virtual bool remove(int id);
    virtual bool update(int id, const T& updatedItem);
    virtual T* get(int id);
    virtual bool exists(int id) const;
    virtual int getCount() const;
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