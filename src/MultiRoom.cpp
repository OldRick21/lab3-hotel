#include "MultiRoom.hpp"

MultiRoom::MultiRoom(int roomNumber, bool isOccupied, int maxGuests, int guestCount, const std::vector<std::string>& guests, double price)
    : roomNumber(roomNumber), occupied(isOccupied), totalSpaces(guestCount), occupiedSpaces(0), maxGuests(maxGuests), guests(guests), dailyRate(price) {
    if (occupiedSpaces > totalSpaces) {
        throw std::invalid_argument("Occupied spaces cannot be greater than total spaces.");
    }
}

void MultiRoom::setGuestCount(int count) {
        occupiedSpaces = count;
    }

int MultiRoom::getMaxGuests()
    {
        return maxGuests;
    }

bool MultiRoom::addGuest(const std::string& guestName) {
    if (guests.size() < maxGuests) {
        guests.push_back(guestName);
        setGuestCount(guests.size());
        return true;
    }
    return false;
}

bool MultiRoom::removeGuest(const std::string& guestName) {
    auto it = std::find_if(guests.begin(), guests.end(), [&guestName](const std::string& guest) {
        return guest == guestName;
    });
    if (it != guests.end()) {
        guests.erase(it);
        setGuestCount(guests.size());
        return true;
    }
    return false;
}

void MultiRoom::clearGuests() {
    guests.clear();
    setGuestCount(0);
}

void MultiRoom::displayInfo() const{
    std::cout << "Multi Room " << roomNumber << ":\n";
    std::cout << "Occupied: " << (occupied ? "Yes" : "No") << "\n";
    std::cout << "Total Spaces: " << totalSpaces << "\n";
    std::cout << "Occupied Spaces: " << occupiedSpaces << "\n";
    std::cout << "Guest Info:\n";
    for (const auto& guest : guestInfo) {
        std::cout << "  Registration Date: " << guest.first << ", Days of Stay: " << guest.second << "\n";
    }
    std::cout << "Daily Rate: " << dailyRate << "\n";
}

std::string MultiRoom::getType() const {
    return "Multi";
}

bool MultiRoom::isOccupied() const {
    return occupied;
}

int MultiRoom::getGuestCount() const {
    return occupiedSpaces;
}

void MultiRoom::occupyRoom(const std::string& registrationDate, int days) {
    guestInfo.emplace_back(registrationDate, days);
    occupiedSpaces++;
    occupied = true;
}

void MultiRoom::vacateRoom() {
    occupied = false;
    occupiedSpaces = 0;
    guestInfo.clear();
}

void MultiRoom::occupyPart(const std::string& registrationDate, int days) {
    if (occupiedSpaces < totalSpaces) {
        guestInfo.emplace_back(registrationDate, days);
        occupiedSpaces++;
        occupied = true;
    } else {
        throw std::runtime_error("No available spaces in the room.");
    }
}


bool MultiRoom::isFull() const {
        return occupiedSpaces >= maxGuests;
    }

bool MultiRoom::isEmpty() const {
        return occupiedSpaces == 0;
    }

const std::vector<std::string>& MultiRoom::getGuests() const {
        return guests;
    }

void MultiRoom::setName(std::string new_name){
        name = new_name;
    }

void MultiRoom::vacatePart() {
    if (occupiedSpaces > 0) {
        guestInfo.pop_back();
        occupiedSpaces--;
        if (occupiedSpaces == 0) {
            occupied = false;
        }
    } else {
        throw std::runtime_error("No guests to vacate.");
    }
}