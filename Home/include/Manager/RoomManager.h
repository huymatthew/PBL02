#ifndef ROOM_MANAGER_H
#define ROOM_MANAGER_H

#include <QStandardItem>
#include <QStandardItemModel>

#include <Data/Room.h>
#include <Core/PrimaryKey.h>
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class RoomManager {
public:
    RoomManager();
    ~RoomManager();

    bool loadFromDatabase();
    bool saveToDatabase();
    
    bool addRoom(const Room& room);
    bool addRoom(const string& roomName, int contractId, int roomType,
                double monthlyRent, const string& description, int status);
    bool removeRoom(int roomId);
    bool updateRoom(int roomId, const Room& updatedRoom);
    
    Room* getRoom(int roomId);
    Room* getRoomByContract(int contractId);
    vector<Room> getRoomsByType(int roomType);
    vector<Room> getRoomsByStatus(int status);
    vector<Room> getAllRooms() const;
    
    bool roomExists(int roomId) const;
    int getRoomCount() const;
    int getAvailableRoomCount() const;
    int getOccupiedRoomCount() const;
    
    bool setRoomOccupied(int roomId, int contractId);
    bool setRoomAvailable(int roomId);
    bool isRoomAvailable(int roomId);
    bool isRoomOccupied(int roomId);

    QStandardItemModel* getRoomsAsModel() const;

    Room* getRoomSelected();
    void setRoomSelected(Room* room);
    
private:
    vector<Room> rooms;
    bool data_loaded;
    PrimaryKey pk_manager;
    Room* selected;
    
    vector<Room>::iterator findRoomIterator(int roomId);
    void sortRoomsById();
    bool isValidRoomId(int roomId) const;
};

#endif // ROOM_MANAGER_H