#ifndef GUEST_H
#define GUEST_H
#include <string>
using namespace std;
enum RoomType{
    Single,
    Twin,
    Family,
    Vip
};
class Room{
    public:

    private:
    string roomID;
    RoomType roomType;
    long price;
    bool isEmpty;
    int size;
    string description;
};


#endif