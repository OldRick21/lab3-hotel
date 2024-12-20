#include "MultiRoom.hpp"
#include <iostream>
#include <algorithm> // Добавьте этот заголовочный файл

MultiRoom::MultiRoom(bool occupied, int totalPlaces, int occupiedPlaces, const std::vector<std::pair<std::string, int>>& guests, double rate)
    : occupied(occupied), totalPlaces(totalPlaces), occupiedPlaces(occupiedPlaces), guests(guests), rate(rate) {}

void MultiRoom::displayInfo() const {
    std::cout << "Multi Room: Occupied=" << occupied << ", TotalPlaces=" << totalPlaces << ", OccupiedPlaces=" << occupiedPlaces
              << ", Rate=" << rate << std::endl;
    for (const auto& guest : guests) {
        std::cout << "Guest: RegistrationDate=" << guest.first << ", Days=" << guest.second << std::endl;
    }
}

std::string MultiRoom::getType() const {
    return "Multi";
}

bool MultiRoom::isOccupied() const {
    return occupied;
}

int MultiRoom::getGuestCount() const {
    return occupiedPlaces;
}

int MultiRoom::getTotalPlaces() const {
    return totalPlaces;
}

int MultiRoom::getOccupiedPlaces() const {
    return occupiedPlaces;
}

void MultiRoom::occupyRoom() {
    occupied = true;
}

void MultiRoom::freeRoom() {
    occupied = false;
}

void MultiRoom::occupyPart(const std::string& registrationDate, int days) {
    if (occupiedPlaces < totalPlaces) {
        guests.push_back({registrationDate, days});
        occupiedPlaces++;
    }
}

void MultiRoom::freePart(const std::string& registrationDate) {
    guests.erase(std::remove_if(guests.begin(), guests.end(), [&](const std::pair<std::string, int>& guest) {
        return guest.first == registrationDate;
    }), guests.end());
    occupiedPlaces--;
}
