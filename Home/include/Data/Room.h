#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include <Core/PrimaryKey.h>
using namespace std;

class Room {
private:
    int room_id;
    string room_name;
    int contract_id; 
    int room_type;
    double monthly_rent;
    string description;
    int status; // 0: trống, 1: đang thuê, ...

public:
    Room();
    Room(const Room& other);
    Room(int id, const string& name, int contractId, int type,
         double rent, const string& desc, int status);

    int getRoomId() const;
    void setRoomId(int id);

    string getRoomName() const;
    void setRoomName(const string& name);

    int getContractId() const;
    void setContractId(int contractId);

    int getRoomType() const;
    void setRoomType(int type);

    double getMonthlyRent() const;
    void setMonthlyRent(double rent);

    string getDescription() const;
    void setDescription(const string& desc);

    int getStatus() const;
    void setStatus(int status);
};

#endif
