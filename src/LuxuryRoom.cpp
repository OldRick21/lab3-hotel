#include "LuxuryRoom.hpp"
#include <iostream>

LuxuryRoom::LuxuryRoom(int number, bool occupied, int roomCount, int guestCount, const std::string& registrationDate, int days, double rate)
    : number(number), occupied(occupied), roomCount(roomCount), guestCount(guestCount), registrationDate(registrationDate), days(days), rate(rate) {}

void LuxuryRoom::displayInfo() const {
    std::cout << "Luxury Room: Number=" << number << ", Occupied=" << occupied << ", RoomCount=" << roomCount << ", GuestCount=" << guestCount
              << ", RegistrationDate=" << registrationDate << ", Days=" << days << ", Rate=" << rate << std::endl;
}

std::string LuxuryRoom::getType() const {
    return "Luxury";
}

bool LuxuryRoom::isOccupied() const {
    return occupied;
}

int LuxuryRoom::getGuestCount() const {
    return guestCount;
}

int LuxuryRoom::getTotalPlaces() const {
    return roomCount;
}

int LuxuryRoom::getOccupiedPlaces() const {
    return guestCount;
}

void LuxuryRoom::occupyRoom() {
    occupied = true;
}

void LuxuryRoom::freeRoom() {
    occupied = false;
}

void LuxuryRoom::setGuestCount(int guestCount) {
    this->guestCount = guestCount;
}
