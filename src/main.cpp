#include "OrderedTable.hpp"
#include "LuxuryRoom.hpp"
#include "SingleRoom.hpp"
#include "MultiRoom.hpp"
#include "OccupancyIterator.hpp"
#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <sstream>

double calculateOccupancy(const OrderedTable<Room*>& table) {
    int totalPlaces = 0;
    int occupiedPlaces = 0;

    OccupancyIterator it(table);
    while (it.hasNext()) {
        const auto& elem = it.next();
        if (dynamic_cast<LuxuryRoom*>(elem.roomDescriptor)) {
            totalPlaces += 2; // Люкс имеет минимум 2 комнаты
            if (elem.roomDescriptor->isOccupied()) {
                occupiedPlaces += elem.roomDescriptor->getGuestCount();
            }
        } else if (dynamic_cast<SingleRoom*>(elem.roomDescriptor)) {
            totalPlaces += 1; // Одноместный номер имеет 1 место
            if (elem.roomDescriptor->isOccupied()) {
                occupiedPlaces += 1;
            }
        } else if (dynamic_cast<MultiRoom*>(elem.roomDescriptor)) {
            totalPlaces += dynamic_cast<MultiRoom*>(elem.roomDescriptor)->getTotalPlaces();
            occupiedPlaces += dynamic_cast<MultiRoom*>(elem.roomDescriptor)->getOccupiedPlaces();
        }
    }

    if (totalPlaces == 0) {
        return 0.0; // Если общее количество мест равно нулю, возвращаем 0% занятости
    }

    return static_cast<double>(occupiedPlaces) / totalPlaces * 100;
}

void registerGuest(OrderedTable<Room*>& roomTable) {
    int roomNumber;
    std::string registrationDate;
    int days;

    std::cout << "Enter room number: ";
    std::cin >> roomNumber;
    std::cout << "Enter registration date: ";
    std::cin >> registrationDate;
    std::cout << "Enter number of days: ";
    std::cin >> days;

    auto room = roomTable.findElement(roomNumber);
    if (room && !room->roomDescriptor->isOccupied()) {
        room->roomDescriptor->occupyRoom();
        if (dynamic_cast<LuxuryRoom*>(room->roomDescriptor)) {
            dynamic_cast<LuxuryRoom*>(room->roomDescriptor)->setGuestCount(1);
        } else if (dynamic_cast<SingleRoom*>(room->roomDescriptor)) {
            // SingleRoom does not need additional settings
        } else if (dynamic_cast<MultiRoom*>(room->roomDescriptor)) {
            dynamic_cast<MultiRoom*>(room->roomDescriptor)->occupyPart(registrationDate, days);
        }
        std::cout << "Guest registered successfully." << std::endl;
    } else {
        std::cout << "Room not found or already occupied." << std::endl;
    }
}

void freeRoom(OrderedTable<Room*>& roomTable) {
    int roomNumber;

    std::cout << "Enter room number: ";
    std::cin >> roomNumber;

    auto room = roomTable.findElement(roomNumber);
    if (room && room->roomDescriptor->isOccupied()) {
        room->roomDescriptor->freeRoom();
        if (dynamic_cast<LuxuryRoom*>(room->roomDescriptor)) {
            dynamic_cast<LuxuryRoom*>(room->roomDescriptor)->setGuestCount(0);
        } else if (dynamic_cast<SingleRoom*>(room->roomDescriptor)) {
            // SingleRoom does not need additional settings
        } else if (dynamic_cast<MultiRoom*>(room->roomDescriptor)) {
            dynamic_cast<MultiRoom*>(room->roomDescriptor)->freePart("");
        }
        std::cout << "Room freed successfully." << std::endl;
    } else {
        std::cout << "Room not found or not occupied." << std::endl;
    }
}

void displayFreeRooms(const OrderedTable<Room*>& roomTable) {
    for (const auto& elem : roomTable.getTable()) {
            elem.roomDescriptor->displayInfo();
    }
}

void displayOccupancy(const OrderedTable<Room*>& roomTable) {
    double occupancy = calculateOccupancy(roomTable);
    std::cout << "Occupancy: " << occupancy << "%" << std::endl;
}

int main() {
    OrderedTable<Room*> roomTable;

    // Пример добавления номеров
    roomTable.addElement(101, new LuxuryRoom(101, false, 2, 0, "2023-10-01", 5, 200.0));
    roomTable.addElement(102, new SingleRoom(102, false, "2023-10-02", 3, 100.0));
    roomTable.addElement(103, new MultiRoom(103, false, 4, 0, {}, 50.0));

    std::string command;
    while (true) {
        std::cout << "Enter command (register, free, display, occupancy, exit): ";
        std::cin >> command;

        if (command == "register") {
            registerGuest(roomTable);
        } else if (command == "free") {
            freeRoom(roomTable);
        } else if (command == "display") {
            displayFreeRooms(roomTable);
        } else if (command == "occupancy") {
            displayOccupancy(roomTable);
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Unknown command." << std::endl;
        }
    }

    // Освобождение памяти
    for (const auto& elem : roomTable.getTable()) {
        delete elem.roomDescriptor;
    }

    return 0;
}
