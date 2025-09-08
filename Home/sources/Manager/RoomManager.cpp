#include <Manager/RoomManager.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

RoomManager::RoomManager() : data_loaded(false) {}

RoomManager::~RoomManager() {}

bool RoomManager::loadFromDatabase() {
    cout << "\033[1;32m*Loading rooms from database...\033[0m" << endl;
    ifstream file("C:\\Qt\\Project\\FirstProject\\Home\\database\\rooms.dat");
    if (!file) {
        cerr << "Error opening rooms.dat for reading." << endl;
        return false;
    }
    
    rooms.clear();
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string roomId;
        int contractId, roomType, status;
        double monthlyRent;
        string description;
        
        if (!(iss >> roomId >> contractId >> roomType >> monthlyRent >> description >> status)) {
            cerr << "Error reading line: " << line << endl;
            continue;
        }
        
        Room room(roomId, contractId, roomType, monthlyRent, description, status);
        rooms.push_back(room);
        cout << "- Loaded room ID: " << roomId << endl;
    }
    
    data_loaded = true;
    return true;
}

bool RoomManager::saveToDatabase() {
    cout << "\033[1;33m*Saving rooms to database...\033[0m" << endl;
    ofstream file("C:\\Qt\\Project\\FirstProject\\Home\\database\\rooms.dat", ios::out | ios::trunc);
    if (!file) {
        cerr << "Error opening rooms.dat for writing." << endl;
        return false;
    }
    
    for (const auto& room : rooms) {
        file << room.getRoomId() << " "
             << room.getContractId() << " "
             << room.getRoomType() << " "
             << room.getMonthlyRent() << " "
             << room.getDescription() << " "
             << room.getStatus() << endl;
        cout << "~ Saved room ID: " << room.getRoomId() << endl;
    }
    
    return true;
}

bool RoomManager::addRoom(const Room& room) {
    if (roomExists(room.getRoomId())) {
        cerr << "Room ID already exists: " << room.getRoomId() << endl;
        return false;
    }
    
    rooms.push_back(room);
    cout << "+ Added room ID: " << room.getRoomId() << endl;
    return true;
}

bool RoomManager::addRoom(const string& roomId, int contractId, int roomType,
                         double monthlyRent, const string& description, int status) {
    Room newRoom(roomId, contractId, roomType, monthlyRent, description, status);
    return addRoom(newRoom);
}

bool RoomManager::removeRoom(const string& roomId) {
    auto it = findRoomIterator(roomId);
    if (it != rooms.end()) {
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
    for (const auto& room : rooms) {
        if (room.getRoomId() == roomId) {
            return true;
        }
    }
    return false;
}

int RoomManager::getRoomCount() const {
    return rooms.size();
}

int RoomManager::getAvailableRoomCount() const {
    int count = 0;
    for (const auto& room : rooms) {
        if (room.getStatus() == 0) { // 0 = available
            count++;
        }
    }
    return count;
}

int RoomManager::getOccupiedRoomCount() const {
    int count = 0;
    for (const auto& room : rooms) {
        if (room.getStatus() == 1) { // 1 = occupied
            count++;
        }
    }
    return count;
}

bool RoomManager::setRoomOccupied(const string& roomId, int contractId) {
    auto it = findRoomIterator(roomId);
    if (it != rooms.end()) {
        it->setStatus(1); // 1 = occupied
        it->setContractId(contractId);
        cout << "* Set room " << roomId << " as occupied with contract " << contractId << endl;
        return true;
    }
    return false;
}

bool RoomManager::setRoomAvailable(const string& roomId) {
    auto it = findRoomIterator(roomId);
    if (it != rooms.end()) {
        it->setStatus(0); // 0 = available
        it->setContractId(0); // No contract
        cout << "* Set room " << roomId << " as available" << endl;
        return true;
    }
    return false;
}

bool RoomManager::isRoomAvailable(const string& roomId) const {
    for (const auto& room : rooms) {
        if (room.getRoomId() == roomId) {
            return room.getStatus() == 0;
        }
    }
    return false;
}

bool RoomManager::isRoomOccupied(const string& roomId) const {
    for (const auto& room : rooms) {
        if (room.getRoomId() == roomId) {
            return room.getStatus() == 1;
        }
    }
    return false;
}

vector<Room> RoomManager::getAvailableRooms() const {
    vector<Room> result;
    for (const auto& room : rooms) {
        if (room.getStatus() == 0) {
            result.push_back(room);
        }
    }
    return result;
}

vector<Room> RoomManager::getOccupiedRooms() const {
    vector<Room> result;
    for (const auto& room : rooms) {
        if (room.getStatus() == 1) {
            result.push_back(room);
        }
    }
    return result;
}

vector<Room> RoomManager::getRoomsByPriceRange(double minPrice, double maxPrice) const {
    vector<Room> result;
    for (const auto& room : rooms) {
        double rent = room.getMonthlyRent();
        if (rent >= minPrice && rent <= maxPrice) {
            result.push_back(room);
        }
    }
    return result;
}

vector<Room> RoomManager::searchRooms(const string& keyword) {
    vector<Room> result;
    for (const auto& room : rooms) {
        if (room.getRoomId().find(keyword) != string::npos ||
            room.getDescription().find(keyword) != string::npos) {
            result.push_back(room);
        }
    }
    return result;
}

vector<Room> RoomManager::searchRoomsByDescription(const string& keyword) {
    vector<Room> result;
    for (const auto& room : rooms) {
        if (room.getDescription().find(keyword) != string::npos) {
            result.push_back(room);
        }
    }
    return result;
}

double RoomManager::getTotalRentRevenue() const {
    double total = 0.0;
    for (const auto& room : rooms) {
        if (room.getStatus() == 1) { // Only occupied rooms
            total += room.getMonthlyRent();
        }
    }
    return total;
}

double RoomManager::getAverageRoomRent() const {
    if (rooms.empty()) return 0.0;
    
    double total = 0.0;
    for (const auto& room : rooms) {
        total += room.getMonthlyRent();
    }
    return total / rooms.size();
}

double RoomManager::getMinRoomRent() const {
    if (rooms.empty()) return 0.0;
    
    double minRent = rooms[0].getMonthlyRent();
    for (const auto& room : rooms) {
        if (room.getMonthlyRent() < minRent) {
            minRent = room.getMonthlyRent();
        }
    }
    return minRent;
}

double RoomManager::getMaxRoomRent() const {
    if (rooms.empty()) return 0.0;
    
    double maxRent = rooms[0].getMonthlyRent();
    for (const auto& room : rooms) {
        if (room.getMonthlyRent() > maxRent) {
            maxRent = room.getMonthlyRent();
        }
    }
    return maxRent;
}

vector<Room> RoomManager::getRoomsSortedByRent(bool ascending) const {
    vector<Room> sortedRooms = rooms;
    sort(sortedRooms.begin(), sortedRooms.end(),
         [ascending](const Room& a, const Room& b) {
             return ascending ? a.getMonthlyRent() < b.getMonthlyRent() :
                               a.getMonthlyRent() > b.getMonthlyRent();
         });
    return sortedRooms;
}

vector<Room> RoomManager::getRoomsSortedById() const {
    vector<Room> sortedRooms = rooms;
    sort(sortedRooms.begin(), sortedRooms.end(),
         [](const Room& a, const Room& b) {
             return a.getRoomId() < b.getRoomId();
         });
    return sortedRooms;
}

// Private helper methods
vector<Room>::iterator RoomManager::findRoomIterator(const string& roomId) {
    for (auto it = rooms.begin(); it != rooms.end(); ++it) {
        if (it->getRoomId() == roomId) {
            return it;
        }
    }
    return rooms.end();
}

void RoomManager::sortRoomsById() {
    sort(rooms.begin(), rooms.end(),
         [](const Room& a, const Room& b) {
             return a.getRoomId() < b.getRoomId();
         });
}

bool RoomManager::isValidRoomId(const string& roomId) const {
    return !roomId.empty() && roomId.length() <= 10;
}
