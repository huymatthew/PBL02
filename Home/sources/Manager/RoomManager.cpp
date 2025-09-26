#include <Manager/RoomManager.h>
#include <Core/ExtraFormat.h>

using namespace std;

RoomManager::RoomManager() : data_loaded(false), pk_manager() {
    loadFromDatabase();
}
RoomManager::~RoomManager() {
    saveToDatabase();
}

bool RoomManager::loadFromDatabase() {
    cout << "\033[1;32m*Loading rooms from database...\033[0m" << endl;
    ifstream file("./Home/database/rooms.dat");
    if (!file) {
        cerr << "Error opening file for reading." << endl;
        return false;
    }
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string roomName, description;
        int contractId, roomType, status, roomId;
        double monthlyRent;
        if (!(iss >> roomId >> roomName >> contractId >> roomType >> monthlyRent >> status)) {
            cerr << "Error reading line: " << line << endl;
            continue; 
        }
        getline(iss, description);
        if (pk_manager.isKeyInUse(roomId)) {
            cerr << "Duplicate room ID found: " << roomId << endl;
            continue; 
        }
        rooms.emplace_back(roomId, roomName, contractId, roomType, monthlyRent, description, status);
        pk_manager.addKey(roomId);
        cout << "- Loaded room ID: " << roomId << endl;
    }
    return true;
}
bool RoomManager::saveToDatabase() {
    cout << "\033[1;33m*Saving rooms to database...\033[0m" << endl;
    ofstream file("./Home/database/rooms.dat", ios::out | ios::trunc);
    if (!file) {
        cerr << "Error opening file for writing." << endl;
        return false;
    }
    for (const auto& room : rooms) {
        file << room.getRoomId() << " "
             << room.getRoomName() << " "
             << room.getContractId() << " "
             << room.getRoomType() << " "
             << room.getMonthlyRent() << " "
             << room.getStatus()
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
bool RoomManager::addRoom(const string &roomName, int contractId, int roomType, double monthlyRent, const string& description, int status) {
    int roomId = pk_manager.getNextKey();
    Room newRoom(roomId, roomName, contractId, roomType, monthlyRent, description, status);
    rooms.push_back(newRoom);
    pk_manager.addKey(roomId);
    cout << "+ Added room ID: " << roomId << endl;
    return true;
}
bool RoomManager::removeRoom(int roomId) {
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
bool RoomManager::updateRoom(int roomId, const Room& updatedRoom) {
    auto it = findRoomIterator(roomId);
    if (it != rooms.end()) {
        *it = updatedRoom;
        cout << "* Updated room ID: " << roomId << endl;
        return true;
    }
    cerr << "Room not found for update: " << roomId << endl;
    return false;
}

Room* RoomManager::getRoom(int roomId) {
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

bool RoomManager::roomExists(int roomId) const {
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

bool RoomManager::setRoomOccupied(int roomId, int contractId) {
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
bool RoomManager::setRoomAvailable(int roomId) {
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
bool RoomManager::isRoomAvailable(int roomId) {
    auto it = findRoomIterator(roomId);
    return it != rooms.end() && it->getStatus() == 0;
}
bool RoomManager::isRoomOccupied(int roomId) {
    auto it = findRoomIterator(roomId);
    return it != rooms.end() && it->getStatus() == 1;
}

// Đoạn ni lười để sau :)))

QStandardItemModel* RoomManager::getRoomsAsModel() const {
    QStandardItemModel* model = new QStandardItemModel();
    model->setColumnCount(7);
    model->setHorizontalHeaderLabels({
        "Mã Phòng", "Tên Phòng", "Mã Hợp Đồng", "Loại Phòng", 
        "Giá Thuê Tháng", "Trạng Thái", "Mô Tả"
    });

    for (const auto& room : rooms) {
        QList<QStandardItem*> rowItems;
        rowItems.append(new QStandardItem(QString::number(room.getRoomId())));
        rowItems.append(new QStandardItem(QString::fromStdString(room.getRoomName())));
        rowItems.append(new QStandardItem(QString::number(room.getContractId())));
        rowItems.append(new QStandardItem(QString::fromStdString(room.getRoomTypeString())));
        rowItems.append(new QStandardItem(moneyFormat(room.getMonthlyRent())));
        rowItems.append(new QStandardItem(room.getStatus() == 0 ? "Available" : "Occupied"));
        rowItems.append(new QStandardItem(QString::fromStdString(room.getDescription())));
        model->appendRow(rowItems);
    }
    return model;
}

vector<Room>::iterator RoomManager::findRoomIterator(int roomId) {
    for (auto it = rooms.begin(); it != rooms.end(); ++it) {
        if (it->getRoomId() == roomId) {
            return it;
        }
    }
    return rooms.end();
}

Room* RoomManager::getRoomSelected() {
    return selected;
}

void RoomManager::setRoomSelected(Room* room) {
    selected = room;
}
