#include <Manager/RoomManager.h>
#include <Core/ExtraFormat.h>

using namespace std;

RoomManager::RoomManager() : Manager<Room>() {}
RoomManager::~RoomManager() {}

bool RoomManager::loadFromDatabase(bool showLog)
{
    cout << "\033[1;32m*Loading rooms from database...\033[0m" << endl;
    ifstream file("./app/database/rooms.dat");
    if (!file)
    {
        cerr << "Error opening file for reading." << endl;
        return false;
    }
    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        string roomName, description;
        int roomType, status, roomId;
        double monthlyRent;
        if (!(iss >> roomId >> roomName >> roomType >> monthlyRent >> status))
        {
            cerr << "Error reading line: " << line << endl;
            continue;
        }
        getline(iss, description);
        if (pk_manager.isKeyInUse(roomId))
        {
            cerr << "Duplicate room ID found: " << roomId << endl;
            continue;
        }
        items.emplace_back(roomId, roomName, roomType, monthlyRent, description, status);
        pk_manager.addKey(roomId);
        if (showLog) cout << "- Loaded room ID: " << roomId << endl;
    }
    return true;
}
bool RoomManager::saveToDatabase(bool showLog)
{
    cout << "\033[1;33m*Saving rooms to database...\033[0m" << endl;
    ofstream file("./app/database/rooms.dat", ios::out | ios::trunc);
    if (!file)
    {
        cerr << "Error opening file for writing." << endl;
        return false;
    }
    for (const auto &room : items)
    {
        file << room.getId() << " "
             << room.getRoomName() << " "
             << room.getRoomType() << " "
             << room.getMonthlyRent() << " "
             << room.getStatus()
             << room.getDescription() << endl;
        if (showLog) cout << "~ Saved room ID: " << room.getId() << endl;
    }
    return true;
}

bool RoomManager::addRoom(const string &roomName, int roomType, double monthlyRent, const string &description, int status)
{
    int roomId = pk_manager.getNextKey();
    Room newRoom(roomId, roomName, roomType, monthlyRent, description, status);
    items.push_back(newRoom);
    pk_manager.addKey(roomId);
    cout << "+ Added room ID: " << roomId << endl;
    return true;
}

Vector<Room> RoomManager::getRoomsByType(int roomType)
{
    Vector<Room> result;
    for (const auto &room : items)
    {
        if (room.getRoomType() == roomType)
        {
            result.push_back(room);
        }
    }
    return result;
}
Vector<Room> RoomManager::getRoomsByStatus(int status)
{
    Vector<Room> result;
    for (const auto &room : items)
    {
        if (room.getStatus() == status)
        {
            result.push_back(room);
        }
    }
    return result;
}
Vector<Room> RoomManager::getAllRooms() const
{
    return items;
}

int RoomManager::getAvailableRoomCount() const
{
    int count = 0;
    for (const auto &room : items)
    {
        if (room.getStatus() == 0)
        { // 0: available
            count++;
        }
    }
    return count;
}
int RoomManager::getOccupiedRoomCount() const
{
    int count = 0;
    for (const auto &room : items)
    {
        if (room.getStatus() == 1)
        { // 1: occupied
            count++;
        }
    }
    return count;
}

bool RoomManager::setRoomOccupied(int roomId)
{
    auto it = this->findIterator(roomId);
    if (it != items.end())
    {
        it->setStatus(1); // 1: occupied
        return true;
    }
    cerr << "Room not found to set as occupied: " << roomId << endl;
    return false;
}
bool RoomManager::setRoomAvailable(int roomId)
{
    auto it = this->findIterator(roomId);
    if (it != items.end())
    {
        it->setStatus(0); // 0: available
        // !#!  it->setContractId(-1); // No contract
        cout << "* Set room ID " << roomId << " as available." << endl;
        return true;
    }
    cerr << "Room not found to set as available: " << roomId << endl;
    return false;
}
bool RoomManager::isRoomAvailable(int roomId)
{
    auto it = this->findIterator(roomId);
    return it != items.end() && it->getStatus() == 0;
}
bool RoomManager::isRoomOccupied(int roomId)
{
    auto it = this->findIterator(roomId);
    return it != items.end() && it->getStatus() == 1;
}

// Đoạn ni lười để sau :)))

QStandardItemModel *RoomManager::getRoomsAsModel() const
{
    QStandardItemModel *model = new QStandardItemModel();
    model->setColumnCount(6);
    model->setHorizontalHeaderLabels({"Mã Phòng", "Tên Phòng", "Loại Phòng",
                                      "Giá Thuê Tháng", "Trạng Thái", "Mô Tả"});

    for (const auto &room : items)
    {
        QList<QStandardItem *> rowItems;
        rowItems.append(new QStandardItem(idnumber(room.getId(), 6)));
        rowItems.append(new QStandardItem(QString::fromStdString(room.getRoomName())));

        QStandardItem* typeItem = new QStandardItem(QString::fromStdString(room.getRoomTypeString()));
        typeItem->setData(room.getRoomType(), Qt::UserRole);
        rowItems.append(typeItem);

        QStandardItem* rentItem = new QStandardItem(moneyFormat(room.getMonthlyRent()));
        rentItem->setData(room.getMonthlyRent(), Qt::UserRole);
        rowItems.append(rentItem);

        QStandardItem* item = new QStandardItem();
        if (room.getStatus() == 1){
            item->setText("Đang thuê");
            item->setForeground(QBrush(Qt::red));
        }
        else{
            item->setText("Trống");
            item->setForeground(QBrush(Qt::darkGreen));
        }
        item->setData(room.getStatus(), Qt::UserRole);
        rowItems.append(item);

        rowItems.append(new QStandardItem(QString::fromStdString(formatSpace(room.getDescription()))));
        model->appendRow(rowItems);
    }
    return model;
}
QStringList RoomManager::getRoomListForComboBox(int filter) const { // 0: all, 1: available, 2: occupied
    QStringList list;
    for (const auto& room : items) {
        if (filter == 0 || (filter == 1 && room.getStatus() == 0) || (filter == 2 && room.getStatus() == 1)) {
            list << QString::fromStdString(room.getRoomName());
        }
    }
    return list;
}


Room *RoomManager::getRoomSelected()
{
    return selected;
}

void RoomManager::setRoomSelected(Room *room)
{
    selected = room;
}

Vector<Room*> RoomManager::getAllAvailableRooms(){
    Vector<Room*> aRooms;
    for (auto r = items.begin(); r != items.end(); ++r) {
        if (r->getStatus() == 0){
            aRooms.push_back(r);
        }
    }
    return aRooms;
}
