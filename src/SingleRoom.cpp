#include "SingleRoom.hpp"

SingleRoom::SingleRoom(int roomNumber, bool occupied, const std::string& registrationDate, int days, double dailyRate)
    : roomNumber(roomNumber), occupied(occupied), registrationDate(registrationDate), days(days), dailyRate(dailyRate) {}

void SingleRoom::displayInfo() const {
    std::cout << "Single Room " << roomNumber << ":\n";
    std::cout << "Occupied: " << (occupied ? "Yes" : "No") << "\n";
    std::cout << "Registration Date: " << registrationDate << "\n";
    std::cout << "Days of Stay: " << days << "\n";
    std::cout << "Daily Rate: " << dailyRate << "\n";
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

void SingleRoom::setName(std::string new_name) {
    name = new_name;
}

const std::string& SingleRoom::getGuestName() const {
    return name;
}

void SingleRoom::occupyRoom(const std::string& registrationDate, int days) {
    this->registrationDate = registrationDate;
    this->days = days;
    occupied = true;
}

void SingleRoom::vacateRoom() {
    occupied = false;
    registrationDate = "";
    days = 0;
}