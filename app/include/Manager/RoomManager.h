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

    bool loadFromDatabase() override;
    bool saveToDatabase() override;
    
    bool add(const Room& room) override;
    bool addRoom(const string& roomName, int roomType,
                double monthlyRent, const string& description, int status);
    bool remove(int roomId) override;
    bool update(int roomId, const Room& updatedRoom) override;
    
    Room* get(int roomId) override;
    Vector<Room> getRoomsByType(int roomType);
    Vector<Room> getRoomsByStatus(int status);
    Vector<Room> getAllRooms() const;
    
    bool exists(int roomId) const override;
    int getCount() const override;
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