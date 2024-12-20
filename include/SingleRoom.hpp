#ifndef SINGLEROOM_HPP
#define SINGLEROOM_HPP

#include "Room.hpp"

class SingleRoom : public Room {
public:
    SingleRoom(bool occupied, const std::string& registrationDate, int days, double rate);
    void displayInfo() const override;
    std::string getType() const override;
    bool isOccupied() const override;
    int getGuestCount() const override;
    int getTotalPlaces() const override;
    int getOccupiedPlaces() const override;
    void occupyRoom() override;
    void freeRoom() override;

private:
    bool occupied;
    std::string registrationDate;
    int days;
    double rate;
};

#endif // SINGLEROOM_HPP
