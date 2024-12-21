#ifndef LUXURYROOM_HPP
#define LUXURYROOM_HPP

#include "Room.hpp"

class LuxuryRoom : public Room {
public:
    LuxuryRoom(int number, bool occupied, int roomCount, int guestCount, const std::string& registrationDate, int days, double rate);
    void displayInfo() const override;
    std::string getType() const override;
    bool isOccupied() const override;
    int getGuestCount() const override;
    int getTotalPlaces() const override;
    int getOccupiedPlaces() const override;
    void occupyRoom() override;
    void freeRoom() override;
    void setGuestCount(int guestCount); // Добавьте этот метод

private:
    int number;
    bool occupied;
    int roomCount;
    int guestCount;
    std::string registrationDate;
    int days;
    double rate;
};

#endif // LUXURYROOM_HPP
