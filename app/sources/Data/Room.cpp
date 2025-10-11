#include <Data/Room.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

Room::Room()
    : room_id(0), room_name(""), room_type(0),
      monthly_rent(0.0), description(""), status(0) {}
Room::Room(const Room& other)
    : room_id(other.room_id), room_name(other.room_name), room_type(other.room_type),
      monthly_rent(other.monthly_rent), description(other.description), status(other.status) {}
Room::Room(int id, const string& name, int type,
         double rent, const string& desc, int status)
    : room_id(id), room_name(name), room_type(type),
      monthly_rent(rent), description(desc), status(status) {}
Room::~Room() {}

int Room::getId() const { return room_id; }
void Room::setId(int id) { room_id = id; }

string Room::getRoomName() const { return room_name; }
void Room::setRoomName(const string& name) { room_name = name; }

int Room::getRoomType() const { return room_type; }
string Room::getRoomTypeString() const {
    switch (room_type) {
        case 0: return "Phòng Đơn";
        case 1: return "Phòng Đôi";
        case 2: return "Phòng Gia Đình";
        default: return "Không Xác Định";
    }
}
void Room::setRoomType(int type) { room_type = type; }

double Room::getMonthlyRent() const { return monthly_rent; }
void Room::setMonthlyRent(double rent) { monthly_rent = rent; }

string Room::getDescription() const { return description; }
void Room::setDescription(const string& desc) { description = desc; }

int Room::getStatus() const { return status; }
void Room::setStatus(int status) { this->status = status; }
