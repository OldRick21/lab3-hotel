#ifndef ORDEREDTABLE_HPP
#define ORDEREDTABLE_HPP

#include <list>
#include <mutex>
#include <algorithm>
#include <iostream>

template <typename T>
class OrderedTable {
public:
    struct Element {
        int roomNumber;
        T roomDescriptor;
    };

    void addElement(int roomNumber, const T& roomDescriptor) {
        std::lock_guard<std::mutex> lock(mtx);
        table.push_back({roomNumber, roomDescriptor});
        table.sort([](const Element& a, const Element& b) {
            return a.roomNumber < b.roomNumber;
        });
    }

    Element* findElement(int roomNumber) {
        std::lock_guard<std::mutex> lock(mtx);
        auto it = std::find_if(table.begin(), table.end(), [roomNumber](const Element& elem) {
            return elem.roomNumber == roomNumber;
        });
        if (it != table.end()) {
            return &(*it);
        }
        return nullptr;
    }

    void removeElement(int roomNumber) {
        std::lock_guard<std::mutex> lock(mtx);
        auto it = std::find_if(table.begin(), table.end(), [roomNumber](const Element& elem) {
            return elem.roomNumber == roomNumber;
        });
        if (it != table.end()) {
            delete it->roomDescriptor; // Освобождение памяти
            table.erase(it);
        }
    }

    void displayTable() const {
        std::lock_guard<std::mutex> lock(mtx);
        for (const auto& elem : table) {
            std::cout << "Room Number: " << elem.roomNumber << ", Descriptor: " << elem.roomDescriptor << std::endl;
        }
    }

    const std::list<Element>& getTable() const { return table; }

private:
    std::list<Element> table;
    mutable std::mutex mtx;
};

#endif // ORDEREDTABLE_HPP
