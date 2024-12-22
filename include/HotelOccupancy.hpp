#pragma once
#include "Table.hpp"
#include "Room.hpp"
#include <vector>
#include <thread>
#include <mutex>

class HotelOccupancy {
private:
    const OrderedTable<Room>& rooms;
    mutable std::mutex mtx;

public:
    HotelOccupancy(const OrderedTable<Room>& rooms) : rooms(rooms) {}

    double calculateOccupancy() const {
        int totalSpaces = 0;
        int occupiedSpaces = 0;

        std::vector<std::thread> threads;
        std::vector<int> results(4, 0); // results[0] for totalSpaces, results[1] for occupiedSpaces, results[2] for totalSpaces, results[3] for occupiedSpaces

        auto processRooms = [&](int start, int end, int index) {
            int localTotalSpaces = 0;
            int localOccupiedSpaces = 0;

            for (int i = start; i < end; ++i) {
                auto it = rooms.begin();
                std::advance(it, i);
                localTotalSpaces += it->getGuestCount();
                if (it->isOccupied()) {
                    localOccupiedSpaces += it->getGuestCount();
                }
            }

            std::lock_guard<std::mutex> lock(mtx);
            results[index] += localTotalSpaces;
            results[index + 1] += localOccupiedSpaces;
        };

        int size = rooms.getSize();
        int mid = size / 2;

        threads.emplace_back(processRooms, 0, mid, 0);
        threads.emplace_back(processRooms, mid, size, 2);

        for (auto& t : threads) {
            t.join();
        }

        totalSpaces = results[0] + results[2];
        occupiedSpaces = results[1] + results[3];

        if (totalSpaces == 0) {
            return 0.0;
        }

        return static_cast<double>(occupiedSpaces) / totalSpaces;
    }
};
