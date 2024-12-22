#include "LuxuryRoom.hpp"

LuxuryRoom::LuxuryRoom(int roomNumber, bool occupied, int numRooms, int numGuests, const std::string& registrationDate, int days, double dailyRate)
    : roomNumber(roomNumber), occupied(occupied), numRooms(numRooms), numGuests(numGuests), registrationDate(registrationDate), days(days), dailyRate(dailyRate) {
    // if (numRooms < 2) {
    //     throw std::invalid_argument("Number of rooms in a luxury room must be at least 2.");
    // }
    // if (numGuests < 1 || numGuests > 2) {
    //     throw std::invalid_argument("Number of guests in a luxury room must be 1 or 2.");
    // }
}

void LuxuryRoom::displayInfo() const {
    std::cout << "Luxury Room " << roomNumber << ":\n";
    std::cout << "Occupied: " << (occupied ? "Yes" : "No") << "\n";
    std::cout << "Number of Rooms: " << numRooms << "\n";
    std::cout << "Number of Guests: " << numGuests << "\n";
    std::cout << "Registration Date: " << registrationDate << "\n";
    std::cout << "Days of Stay: " << days << "\n";
    std::cout << "Daily Rate: " << dailyRate << "\n";
}

std::string LuxuryRoom::getType() const {
    return "Luxury";
}

bool LuxuryRoom::isOccupied() const {
    return occupied;
}

int LuxuryRoom::getGuestCount() const {
    return numGuests;
}

void LuxuryRoom::occupyRoom(const std::string& registrationDate, int days) {
    this->registrationDate = registrationDate;
    this->days = days;
    occupied = true;
}

const std::string& LuxuryRoom::getGuestName() const {
    return name;
}

void LuxuryRoom::setName(std::string new_name) {
    name = new_name;
}

void LuxuryRoom::vacateRoom() {
    occupied = false;
    numGuests = 0;
    registrationDate = "";
    days = 0;
}