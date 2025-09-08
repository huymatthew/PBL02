#include <RoomManager.h>

using namespace std;

RoomManager::RoomManager() : data_loaded(false), pk_manager() {
    loadFromDatabase();
}
RoomManager::~RoomManager() {
    saveToDatabase();
}

bool RoomManager::loadFromDatabase() {
    cout << "\033[1;32m*Loading rooms from database...\033[0m" << endl;
    ifstream file("C:\\Qt\\Project\\FirstProject\\Home\\database\\rooms.dat");
    if (!file) {
        cerr << "Error opening file for reading." << endl;
        return false;
    }
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string roomId, description;
        int contractId, roomType, status;
        double monthlyRent;
        if (!(iss >> roomId >> contractId >> roomType >> monthlyRent >> status)) {
            cerr << "Error reading line: " << line << endl;
            continue; // Skip malformed lines
        }
        getline(iss, description); // Read the rest of the line as description
        if (pk_manager.isKeyInUse(roomId)) {
            cerr << "Duplicate room ID found: " << roomId << endl;
            continue; // Skip duplicate IDs
        }
        rooms.emplace_back(roomId, contractId, roomType, monthlyRent, description, status);
        pk_manager.addKey(roomId);
        cout << "- Loaded room ID: " << roomId << endl;
    }
    return true;
}
bool RoomManager::saveToDatabase() {
    cout << "\033[1;33m*Saving rooms to database...\033[0m" << endl;
    ofstream file("C:\\Qt\\Project\\FirstProject\\Home\\database\\rooms.dat", ios::out | ios::trunc);
    if (!file) {
        cerr << "Error opening file for writing." << endl;
        return false;
    }
    for (const auto& room : rooms) {
        file << room.getRoomId() << " "
             << room.getContractId() << " "
             << room.getRoomType() << " "
             << room.getMonthlyRent() << " "
             << room.getStatus() << " "
             << room.getDescription() << endl;
        cout << "~ Saved room ID: " << room.getRoomId() << endl;
    }
    return true;
}

bool RoomManager::addRoom(const Room& room) {
    if (pk_manager.isKeyInUse(room.getRoomId())) {
        cerr << "Room ID already in use: " << room.getRoomId() << endl;
        return false;
    }
    rooms.push_back(room);
    pk_manager.addKey(room.getRoomId());
    cout << "+ Added room ID: " << room.getRoomId() << endl;
    return true;
}
bool RoomManager::addRoom(const string& roomId, int contractId, int roomType, double monthlyRent, const string& description, int status) {
    if (pk_manager.isKeyInUse(roomId)) {
        cerr << "Room ID already in use: " << roomId << endl;
        return false;
    }
    Room newRoom(roomId, contractId, roomType, monthlyRent, description, status);
    rooms.push_back(newRoom);
    pk_manager.addKey(roomId);
    cout << "+ Added room ID: " << roomId << endl;
    return true;
}
bool RoomManager::removeRoom(const string& roomId) {
    auto it = findRoomIterator(roomId);
    if (it != rooms.end()) {
        pk_manager.releaseKey(roomId);
        rooms.erase(it);
        cout << "- Removed room ID: " << roomId << endl;
        return true;
    }
    cerr << "Room not found for removal: " << roomId << endl;
    return false;
}
bool RoomManager::updateRoom(const string& roomId, const Room& updatedRoom) {
    auto it = findRoomIterator(roomId);
    if (it != rooms.end()) {
        *it = updatedRoom;
        cout << "* Updated room ID: " << roomId << endl;
        return true;
    }
    cerr << "Room not found for update: " << roomId << endl;
    return false;
}

Room* RoomManager::getRoom(const string& roomId) {
    auto it = findRoomIterator(roomId);
    if (it != rooms.end()) {
        return &(*it);
    }
    return nullptr;
}
Room* RoomManager::getRoomByContract(int contractId) {
    for (auto& room : rooms) {
        if (room.getContractId() == contractId) {
            return &room;
        }
    }
    return nullptr;
}
vector<Room> RoomManager::getRoomsByType(int roomType) {
    vector<Room> result;
    for (const auto& room : rooms) {
        if (room.getRoomType() == roomType) {
            result.push_back(room);
        }
    }
    return result;
}
vector<Room> RoomManager::getRoomsByStatus(int status) {
    vector<Room> result;
    for (const auto& room : rooms) {
        if (room.getStatus() == status) {
            result.push_back(room);
        }
    }
    return result;
}
vector<Room> RoomManager::getAllRooms() const {
    return rooms;
}

bool RoomManager::roomExists(const string& roomId) const {
    return pk_manager.isKeyInUse(roomId);
}
int RoomManager::getRoomCount() const {
    return rooms.size();
}
int RoomManager::getAvailableRoomCount() const {
    int count = 0;
    for (const auto& room : rooms) {
        if (room.getStatus() == 0) { // 0: available
            count++;
        }
    }
    return count;
}
int RoomManager::getOccupiedRoomCount() const {
    int count = 0;
    for (const auto& room : rooms) {
        if (room.getStatus() == 1) { // 1: occupied
            count++;
        }
    }
    return count;
}

bool RoomManager::setRoomOccupied(const string& roomId, int contractId) {
    auto it = findRoomIterator(roomId);
    if (it != rooms.end()) {
        it->setStatus(1); // 1: occupied
        it->setContractId(contractId);
        cout << "* Set room ID " << roomId << " as occupied with contract ID: " << contractId << endl;
        return true;
    }
    cerr << "Room not found to set as occupied: " << roomId << endl;
    return false;
}
bool RoomManager::setRoomAvailable(const string& roomId) {
    auto it = findRoomIterator(roomId);
    if (it != rooms.end()) {
        it->setStatus(0); // 0: available
        it->setContractId(-1); // No contract
        cout << "* Set room ID " << roomId << " as available." << endl;
        return true;
    }
    cerr << "Room not found to set as available: " << roomId << endl;
    return false;
}
bool RoomManager::isRoomAvailable(const string& roomId) {
    auto it = findRoomIterator(roomId);
    return it != rooms.end() && it->getStatus() == 0;
}
bool RoomManager::isRoomOccupied(const string& roomId) {
    auto it = findRoomIterator(roomId);
    return it != rooms.end() && it->getStatus() == 1;
}

// Đoạn ni lười để sau :)))

vector<Room>::iterator RoomManager::findRoomIterator(const string& roomId) {
    for (auto it = rooms.begin(); it != rooms.end(); ++it) {
        if (it->getRoomId() == roomId) {
            return it;
        }
    }
    return rooms.end();
}

