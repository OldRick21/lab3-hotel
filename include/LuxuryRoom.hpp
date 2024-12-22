#pragma once
#include "Room.hpp"

class LuxuryRoom : public Room {
public:
    LuxuryRoom(int roomNumber, bool occupied, int numRooms, int numGuests, const std::string& registrationDate, int days, double dailyRate);
    void displayInfo() const override;
    RoomType getType() const override;
    bool isOccupied() const override;
    int getGuestCount() const override;
    void occupyRoom(const std::string& registrationDate, int days) override;
    const std::string &getGuestName() const;
    void setName(std::string new_name);
    void vacateRoom() override;
    bool operator==(const Room& other) const override {
        const LuxuryRoom* otherLuxuryRoom = dynamic_cast<const LuxuryRoom*>(&other);
        if (otherLuxuryRoom) {
            return roomNumber == otherLuxuryRoom->roomNumber;
        }
        return false;
    }

    int getRoomNumber() const {return roomNumber;}

    bool operator<(const Room& other) const override {
        const LuxuryRoom* otherLuxuryRoom = dynamic_cast<const LuxuryRoom*>(&other);
        if (otherLuxuryRoom) {
            return roomNumber < otherLuxuryRoom->roomNumber;
        }
        return false;
    }

    bool operator>(const Room& other) const override {
        const LuxuryRoom* otherLuxuryRoom = dynamic_cast<const LuxuryRoom*>(&other);
        if (otherLuxuryRoom) {
            return roomNumber > otherLuxuryRoom->roomNumber;
        }
        return false;
    }

private:
    int roomNumber;
    bool occupied;
    int numRooms;
    int numGuests;
    std::string registrationDate;
    std::string name;
    int days;
    double dailyRate;
};