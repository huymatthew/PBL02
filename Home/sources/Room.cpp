#include <Room.h>

// Default constructor
Room::Room()
    : room_id(""), contract_id(0), room_type(0),
      monthly_rent(0.0), description(""), status(0) {}

// Copy constructor
Room::Room(const Room& other)
    : room_id(other.room_id), contract_id(other.contract_id),
      room_type(other.room_type), monthly_rent(other.monthly_rent),
      description(other.description), status(other.status) {}

// Parameterized constructor
Room::Room(const string& id, int contractId, int type,
           double rent, const string& desc, int status)
    : room_id(id), contract_id(contractId), room_type(type),
      monthly_rent(rent), description(desc), status(status) {}

// Getter - Setter implementations
string Room::getRoomId() const { return room_id; }
void Room::setRoomId(const string& id) { room_id = id; }

int Room::getContractId() const { return contract_id; }
void Room::setContractId(int contractId) { contract_id = contractId; }

int Room::getRoomType() const { return room_type; }
void Room::setRoomType(int type) { room_type = type; }

double Room::getMonthlyRent() const { return monthly_rent; }
void Room::setMonthlyRent(double rent) { monthly_rent = rent; }

string Room::getDescription() const { return description; }
void Room::setDescription(const string& desc) { description = desc; }

int Room::getStatus() const { return status; }
void Room::setStatus(int status) { this->status = status; }

// Stub for loading rooms from database
vector<Room> Room::loadFromDatabase() {
    // TODO: Implement database loading logic
    return vector<Room>();
}

// Stub for saving a room to database
bool Room::saveToDatabase(const Room& room) {
    // TODO: Implement database saving logic
    return true;
}