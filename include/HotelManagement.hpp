#include <iostream>
#include <memory>
#include <string>
#include "Table.hpp"
#include "LuxuryRoom.hpp"
#include "MultiRoom.hpp"
#include "SingleRoom.hpp"
#include "HotelOccupancy.hpp"

class HotelManagement {
private:
    OrderedTable<Room> rooms;

public:
    void addRoom(Room* room);
    void registerGuest(const std::string& guestName, int roomNumber, const std::string& registrationDate, int days);
    void registerGuest(const std::string& guestName, int roomNumber);
    void removeGuest(const std::string& guestName, int roomNumber);
    void checkoutGuest(int roomNumber);
    void listAvailableRooms() const;
    void listMultiRooms() const;
    void listFullRooms() const;
    double calculateOccupancy() const;
};