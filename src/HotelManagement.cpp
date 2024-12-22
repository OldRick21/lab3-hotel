#include "HotelManagement.hpp"

    void HotelManagement::addRoom(Room* room) {
        rooms.insert(room);
    }

    void HotelManagement::registerGuest(const std::string& guestName, int roomNumber, const std::string& registrationDate, int days) {
    for (auto it = rooms.begin(); it != rooms.end(); ++it) {
        if (it->getRoomNumber() == roomNumber) {
            if (!it->isOccupied()) {
                it->setName(guestName);
                it->occupyRoom(registrationDate, days);
                std::cout << "Guest " << guestName << " successfully registered in room " << roomNumber << std::endl;
                return;
            }
        }
    }
    std::cout << "Room " << roomNumber << " is not available or does not exist." << std::endl;
}

    void HotelManagement::registerGuest(const std::string& guestName, int roomNumber) {
        for (auto it = rooms.begin(); it != rooms.end(); ++it) {
            if (it->getRoomNumber() == roomNumber) {
                if (dynamic_cast<MultiRoom*>(it.operator->()) != nullptr) {
                    MultiRoom* multiRoom = dynamic_cast<MultiRoom*>(it.operator->());
                    if (multiRoom->getGuestCount() < multiRoom->getMaxGuests()) {
                        multiRoom->addGuest(guestName);
                        std::cout << "Guest " << guestName << " successfully registered in room " << roomNumber << std::endl;
                        return;
                    } else {
                        std::cout << "Room " << roomNumber << " is full." << std::endl;
                        return;
                    }
                } else {
                    std::cout << "Room " << roomNumber << " is not a MultiRoom." << std::endl;
                    return;
                }
            }
        }
        std::cout << "Room " << roomNumber << " does not exist." << std::endl;
    }


    void HotelManagement::removeGuest(const std::string& guestName, int roomNumber) {
        for (auto it = rooms.begin(); it != rooms.end(); ++it) {
            if (it->getRoomNumber() == roomNumber) {
                if (dynamic_cast<MultiRoom*>(it.operator->()) != nullptr) {
                    MultiRoom* multiRoom = dynamic_cast<MultiRoom*>(it.operator->());
                    if (multiRoom->removeGuest(guestName)) {
                        std::cout << "Guest " << guestName << " successfully removed from room " << roomNumber << std::endl;
                        return;
                    } else {
                        std::cout << "Guest " << guestName << " not found in room " << roomNumber << std::endl;
                        return;
                    }
                } else {
                    std::cout << "Room " << roomNumber << " is not a MultiRoom." << std::endl;
                    return;
                }
            }
        }
        std::cout << "Room " << roomNumber << " does not exist." << std::endl;
    }

    void HotelManagement::listAvailableRooms() const {
        std::cout << "Available rooms:" << std::endl;
        for (auto it = rooms.begin(); it != rooms.end(); ++it) {
            if (!it->isOccupied() && it->getType() != "Multi") {
                std::cout << "Room " << it->getRoomNumber() << " (" << it->getType() << ")" << std::endl;
            }
        }
    }

    void HotelManagement::listMultiRooms() const {
        std::cout << "MultiRooms and their occupancy:" << std::endl;
        for (auto it = rooms.begin(); it != rooms.end(); ++it) {
            if (dynamic_cast<const MultiRoom*>(it.operator->()) != nullptr) {
                const MultiRoom* multiRoom = dynamic_cast<const MultiRoom*>(it.operator->());
                std::cout << "Room " << multiRoom->getRoomNumber() << " (" << multiRoom->getType() << "): ";
                if (multiRoom->isFull()) {
                    std::cout << "Full";
                } else if (multiRoom->isEmpty()) {
                    std::cout << "Empty";
                } else {
                    std::cout << "Partially occupied";
                }
                std::cout << std::endl;
            }
        }
    }

void HotelManagement::listFullRooms() const {
    std::cout << "Full rooms:" << std::endl;
    for (auto it = rooms.begin(); it != rooms.end(); ++it) {
        if (it->isOccupied()) {
            std::cout << "Room " << it->getRoomNumber() << " (" << it->getType() << ")" << std::endl;
            if (dynamic_cast<const MultiRoom*>(it.operator->()) != nullptr) {
                const MultiRoom* multiRoom = dynamic_cast<const MultiRoom*>(it.operator->());
                const std::vector<std::string>& guests = multiRoom->getGuests();
                for (const auto& guest : guests) {
                    std::cout << "  Guest: " << guest << std::endl;
                }
            } else if (dynamic_cast<const SingleRoom*>(it.operator->()) != nullptr) {
                const SingleRoom* singleRoom = dynamic_cast<const SingleRoom*>(it.operator->());
                std::cout << "  Guest: " << singleRoom->getGuestName() << std::endl;
            } else if (dynamic_cast<const LuxuryRoom*>(it.operator->()) != nullptr) {
                const LuxuryRoom* luxuryRoom = dynamic_cast<const LuxuryRoom*>(it.operator->());
                std::cout << "  Guest: " << luxuryRoom->getGuestName() << std::endl;
            }
        }
    }
}

    double HotelManagement::calculateOccupancy() const {
        HotelOccupancy occupancy(rooms);
        double occupancyRate = occupancy.calculateOccupancy();
        if (occupancyRate > 0.8) {
            std::cout << "Warning: Hotel occupancy is over 80%!" << std::endl;
        }
        return occupancyRate;
    }

void HotelManagement::checkoutGuest(int roomNumber) {
    for (auto it = rooms.begin(); it != rooms.end(); ++it) {
        if (it->getRoomNumber() == roomNumber) {
            if (dynamic_cast<MultiRoom*>(it.operator->()) != nullptr) {
                std::cout << "Cannot checkout from a MultiRoom using this option. Use option 7 instead." << std::endl;
                return;
            } else if (it->isOccupied()) {
                it->vacateRoom();
                std::cout << "Room " << roomNumber << " is now available." << std::endl;
                return;
            }
        }
    }
    std::cout << "Room " << roomNumber << " is already available or does not exist." << std::endl;
}