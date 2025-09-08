#ifndef ROOM_MANAGER_H
#define ROOM_MANAGER_H

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

    // Database operations
    bool loadFromDatabase();
    bool saveToDatabase();
    
    // CRUD operations
    bool addRoom(const Room& room);
    bool addRoom(const string& roomId, int contractId, int roomType,
                double monthlyRent, const string& description, int status);
    bool removeRoom(const string& roomId);
    bool updateRoom(const string& roomId, const Room& updatedRoom);
    
    // Query operations
    Room* getRoom(const string& roomId);
    Room* getRoomByContract(int contractId);
    vector<Room> getRoomsByType(int roomType);
    vector<Room> getRoomsByStatus(int status);
    vector<Room> getAllRooms() const;
    
    // Utility operations
    bool roomExists(const string& roomId) const;
    int getRoomCount() const;
    int getAvailableRoomCount() const;
    int getOccupiedRoomCount() const;
    
    // Status management
    bool setRoomOccupied(const string& roomId, int contractId);
    bool setRoomAvailable(const string& roomId);
    bool isRoomAvailable(const string& roomId);
    bool isRoomOccupied(const string& roomId);
    
    // Type management
    vector<Room> getAvailableRooms() const;
    vector<Room> getOccupiedRooms() const;
    vector<Room> getRoomsByPriceRange(double minPrice, double maxPrice) const;
    
    // Search operations
    vector<Room> searchRooms(const string& keyword);
    vector<Room> searchRoomsByDescription(const string& keyword);
    
    // Financial operations
    double getTotalRentRevenue() const;
    double getAverageRoomRent() const;
    double getMinRoomRent() const;
    double getMaxRoomRent() const;
    
    // Sorting operations
    vector<Room> getRoomsSortedByRent(bool ascending = true) const;
    vector<Room> getRoomsSortedById() const;
    
private:
    vector<Room> rooms;
    bool data_loaded;
    PrimaryKey<string> pk_manager;
    
    // Helper methods
    vector<Room>::iterator findRoomIterator(const string& roomId);
    void sortRoomsById();
    bool isValidRoomId(const string& roomId) const;
};

#endif // ROOM_MANAGER_H