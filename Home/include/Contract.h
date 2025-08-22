#ifndef GUEST_H
#define GUEST_H
#include <string>
using namespace std;

#include "Guest.h"
#include "Room.h"


class Contract{
    public:

    private:
    string contractID;
    string guestID;
    string roomID;
    string dateBegin;
    string dateEx;
    long price;
    long deposit;
    bool isActive;
};


#endif