#ifndef ROOM_MANAGER_H
#define ROOM_MANAGER_H

#include <QStandardItem>
#include <QStandardItemModel>
#include <Core/Manager.h>

#include <Data/Room.h>
#include <Core/PrimaryKey.h>
#include <Core/cVector.h>
#include <string>
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
class DataManager;

class RoomManager : public Manager<Room> {
public:
    RoomManager();
    ~RoomManager();

    bool loadFromDatabase(bool showLog = false) override;
    bool saveToDatabase(bool showLog = false) override;
    
    bool addRoom(const string& roomName, int roomType,
                double monthlyRent, const string& description, int status);

    Vector<Room> getRoomsByType(int roomType);
    Vector<Room> getRoomsByStatus(int status);
    Vector<Room> getAllRooms() const;

    int getAvailableRoomCount() const;
    int getOccupiedRoomCount() const;
    
    bool setRoomOccupied(int roomId);
    bool setRoomAvailable(int roomId);
    bool isRoomAvailable(int roomId);
    bool isRoomOccupied(int roomId);

    QStandardItemModel* getRoomsAsModel() const;
    QStringList getRoomListForComboBox(int filter = 0) const;

    Room* getRoomSelected();
    void setRoomSelected(Room* room);

    Vector<Room*> getAllAvailableRooms();
    
private:
    Room* selected;
    friend class DataManager;
};

#endif // ROOM_MANAGER_H