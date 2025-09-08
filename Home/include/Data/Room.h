#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include <Core/PrimaryKey.h>
using namespace std;

class Room {
private:
    string room_id;
    int contract_id;       // FK -> Contracts
    int room_type;
    double monthly_rent;
    string description;
    int status; // 0: trống, 1: đang thuê, ...

public:
    Room();
    Room(const Room& other);
    Room(const string& id, int contractId, int type,
         double rent, const string& desc, int status);

    static vector<Room> loadFromDatabase();
    static bool saveToDatabase(const vector<Room>& rooms);

    // Getter - Setter
    string getRoomId() const;
    void setRoomId(const string& id);

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
