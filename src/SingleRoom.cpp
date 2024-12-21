#include "SingleRoom.hpp"
#include <iostream>

SingleRoom::SingleRoom(int number, bool occupied, const std::string& registrationDate, int days, double rate)
    : number(number), occupied(occupied), registrationDate(registrationDate), days(days), rate(rate) {}

void SingleRoom::displayInfo() const {
    std::cout << "Single Room: Number=" << number << ", Occupied=" << occupied << ", RegistrationDate=" << registrationDate << ", Days=" << days << ", Rate=" << rate << std::endl;
}

std::string SingleRoom::getType() const {
    return "Single";
}

bool SingleRoom::isOccupied() const {
    return occupied;
}

int SingleRoom::getGuestCount() const {
    return occupied ? 1 : 0;
}

int SingleRoom::getTotalPlaces() const {
    return 1;
}

int SingleRoom::getOccupiedPlaces() const {
    return occupied ? 1 : 0;
}

void SingleRoom::occupyRoom() {
    occupied = true;
}

void SingleRoom::freeRoom() {
    occupied = false;
}
