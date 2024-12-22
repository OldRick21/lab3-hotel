#pragma once
#include "Room.hpp"
#include <vector>
#include <algorithm>

class MultiRoom : public Room {

private:
    int roomNumber;
    bool occupied;
    int totalSpaces;
    int occupiedSpaces;
    std::vector<std::pair<std::string, int>> guestInfo;
    double dailyRate;
    std::vector<std::string> guests;
    int maxGuests;
    std::string name;

public:
    MultiRoom(int roomNumber, bool isOccupied, int maxGuests, int guestCount, const std::vector<std::string>& guests, double price);

    RoomType getType() const override;
    bool isOccupied() const override;
    void displayInfo() const override;
    int getGuestCount() const override;
    void occupyRoom(const std::string& registrationDate, int days) override;
    void vacateRoom() override;
    void occupyPart(const std::string& registrationDate, int days);
    bool isFull() const;
    bool isEmpty() const;
    const std::vector<std::string> &getGuests() const;
    void setName(std::string new_name);
    void vacatePart();

    bool addGuest(const std::string& guestName);

    bool removeGuest(const std::string &guestName);

    void setGuestCount(int count);

    int getMaxGuests();

    void clearGuests();

    bool operator==(const Room& other) const override {
            const MultiRoom* otherLuxuryRoom = dynamic_cast<const MultiRoom*>(&other);
            if (otherLuxuryRoom) {
                return roomNumber == otherLuxuryRoom->roomNumber;
            }
            return false;
        }

    bool operator<(const Room& other) const override {
        const MultiRoom* otherLuxuryRoom = dynamic_cast<const MultiRoom*>(&other);
        if (otherLuxuryRoom) {
            return roomNumber < otherLuxuryRoom->roomNumber;
        }
        return false;
    }

    int getRoomNumber() const {return roomNumber;}


    bool operator>(const Room& other) const override {
        const MultiRoom* otherLuxuryRoom = dynamic_cast<const MultiRoom*>(&other);
        if (otherLuxuryRoom) {
            return roomNumber > otherLuxuryRoom->roomNumber;
        }
        return false;
    }


};