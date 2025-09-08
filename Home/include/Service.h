#ifndef SERVICE_H
#define SERVICE_H

#include <string>
#include <vector>
#include <PrimaryKey.h>
using namespace std;

class Service {
private:
    int service_id;
    int service_type; // enum: 0 = Điện, 1 = Nước, 2 = Internet, ...
    int bill_id;      // FK -> Bill
    int quantity;
    double price;

    static PrimaryKey<int> pk_manager;
public:
    Service();
    Service(const Service& other);
    Service(int id, int type, int billId, int qty, double price);

    static vector<Service> loadFromDatabase();
    static bool saveToDatabase(const Service& service);

    // Getter - Setter
    int getServiceId() const;
    void setServiceId(int id);

    int getServiceType() const;
    void setServiceType(int type);

    int getBillId() const;
    void setBillId(int billId);

    int getQuantity() const;
    void setQuantity(int qty);

    double getPrice() const;
    void setPrice(double price);
};

#endif
