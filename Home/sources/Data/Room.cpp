#include <Data/Room.h>
#include <iostream>
#include <fstream>
#include <sstream>

PrimaryKey<string> Room::pk_manager = PrimaryKey<string>();

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
    vector<Room> rooms;
    cout << "\033[1;32m*Loading rooms from database...\033[0m" << endl;
    ifstream file("C:\\Qt\\Project\\FirstProject\\Home\\database\\rooms.dat");
    if (!file) {
        cerr << "Error opening rooms file for reading." << endl;
        return rooms;
    }
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string roomId, description;
        int contractId, roomType, status;
        double monthlyRent;
        
        if (!(iss >> roomId >> contractId >> roomType >> monthlyRent >> description >> status)) {
            cerr << "Error reading room line: " << line << endl;
            continue;
        }
        if (pk_manager.isKeyInUse(roomId)) {
            cerr << "Duplicate room ID found: " << roomId << endl;
            continue;
        }
        rooms.emplace_back(roomId, contractId, roomType, monthlyRent, description, status);
        cout << "- Loaded room ID: " << roomId << endl;
    }
    return rooms;
}

// Stub for saving room to database
bool Room::saveToDatabase(const vector<Room>& rooms) {
    cout << "\033[1;33m*Saving rooms to database...\033[0m" << endl;
    ofstream file("C:\\Qt\\Project\\FirstProject\\Home\\database\\rooms.dat", ios::out | ios::trunc);
    if (!file) {
        cerr << "Error opening rooms file for writing." << endl;
        return false;
    }
    file.clear();
    for (const auto& room : rooms) {
        file << room.room_id << " "
             << room.contract_id << " "
             << room.room_type << " "
             << room.monthly_rent << " "
             << room.description << " "
             << room.status << endl;
        cout << "~ Saved room ID: " << room.room_id << endl;
    }
    return true;
}