#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>

class Room {
public:
    virtual void displayInfo() const = 0;
    virtual std::string getType() const = 0;
    virtual bool isOccupied() const = 0;
    virtual int getGuestCount() const = 0;
    virtual int getTotalPlaces() const = 0; // Добавьте этот метод
    virtual int getOccupiedPlaces() const = 0; // Добавьте этот метод
    virtual void occupyRoom() = 0;
    virtual void freeRoom() = 0;
    virtual ~Room() = default;
};

#endif // ROOM_HPP