#pragma once
#include <string>
#include <iostream>
#include <stdexcept>

class Room {
public:
    virtual ~Room() = default;
    virtual void displayInfo() const = 0;
    virtual std::string getType() const = 0;
    virtual bool isOccupied() const = 0;
    virtual int getRoomNumber() const = 0;
    virtual int getGuestCount() const = 0;
    virtual void occupyRoom(const std::string& registrationDate, int days) = 0;
    virtual void vacateRoom() = 0;
    virtual void setName(std::string new_name) = 0;
    virtual bool operator==(const Room& other)const = 0;
    virtual bool operator<(const Room& other) const = 0; 
    virtual bool operator>(const Room& other) const = 0; 
};