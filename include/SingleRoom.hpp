#pragma once
#include "Room.hpp"

class SingleRoom : public Room {
public:
    SingleRoom(int roomNumber, bool occupied, const std::string& registrationDate, int days, double dailyRate);
    void displayInfo() const override;
    std::string getType() const override;
    bool isOccupied() const override;
    int getGuestCount() const override;
    void setName(std::string new_name);
    const std::string &getGuestName() const;
    void occupyRoom(const std::string &registrationDate, int days) override;
    void vacateRoom() override;
bool operator==(const Room& other) const override {
        const SingleRoom* otherLuxuryRoom = dynamic_cast<const SingleRoom*>(&other);
        if (otherLuxuryRoom) {
            return roomNumber == otherLuxuryRoom->roomNumber;
        }
        return false;
    }

    bool operator<(const Room& other) const override {
        const SingleRoom* otherLuxuryRoom = dynamic_cast<const SingleRoom*>(&other);
        if (otherLuxuryRoom) {
            return roomNumber < otherLuxuryRoom->roomNumber;
        }
        return false;
    }

    int getRoomNumber() const {return roomNumber;}


    bool operator>(const Room& other) const override {
        const SingleRoom* otherLuxuryRoom = dynamic_cast<const SingleRoom*>(&other);
        if (otherLuxuryRoom) {
            return roomNumber > otherLuxuryRoom->roomNumber;
        }
        return false;
    }



private:
    int roomNumber;
    bool occupied;
    std::string registrationDate;
    int days;
    std::string name;
    double dailyRate;
};