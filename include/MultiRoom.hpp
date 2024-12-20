#ifndef MULTIROOM_HPP
#define MULTIROOM_HPP

#include "Room.hpp"
#include <vector>
#include <utility>
#include <string>

class MultiRoom : public Room {
public:
    MultiRoom(bool occupied, int totalPlaces, int occupiedPlaces, const std::vector<std::pair<std::string, int>>& guests, double rate);
    void displayInfo() const override;
    std::string getType() const override;
    bool isOccupied() const override;
    int getGuestCount() const override;
    int getTotalPlaces() const override;
    int getOccupiedPlaces() const override;
    void occupyRoom() override;
    void freeRoom() override;
    void occupyPart(const std::string& registrationDate, int days);
    void freePart(const std::string& registrationDate);

private:
    bool occupied;
    int totalPlaces;
    int occupiedPlaces;
    std::vector<std::pair<std::string, int>> guests;
    double rate;
};

#endif // MULTIROOM_HPP
