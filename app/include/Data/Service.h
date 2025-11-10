#ifndef SERVICE_H
#define SERVICE_H

#include <string>
#include <Core/cVector.h>
#include <Core/PrimaryKey.h>
using namespace std;

class Service {
private:
    int service_id;
    int service_type; // enum: 0 = Điện, 1 = Nước, 2 = Internet, ...
    int bill_id;    
    int quantity;
    double price;

public:
    Service();
    Service(const Service& other);
    Service(int id, int type, int billId, int qty, double price);
    ~Service();

    int getId() const;
    void setId(int id);

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
