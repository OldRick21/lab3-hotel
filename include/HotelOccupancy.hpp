#pragma once

#include "Table.hpp"
#include "Room.hpp"
#include <vector>
#include <thread>
#include <mutex>

class HotelOccupancy {
private:
    const OrderedTable<Room> &rooms;
    mutable std::mutex mtx;

public:
    HotelOccupancy(const OrderedTable<Room> &rooms) : rooms(rooms) {}

    double calculateOccupancy() const {
        int totalSpaces = 0;
        int occupiedSpaces = 0;

        std::vector<std::thread> threads;
        std::vector<int> results(6,
                                 0); // четный - totalSpaces, нечетный - occupiedSpaces, 0/1 - luxury, 2/3 - single, 4/5 - multi

        auto processRooms = [&](int start, int end, int index, RoomType roomType) {
            int localTotalSpaces = 0;
            int localOccupiedSpaces = 0;
            auto it = rooms.begin();

            for (int i = start; i < end; ++i) {
                if (roomType == it->getType()) {
                    if (roomType == static_cast<RoomType>(2)) {
                        localTotalSpaces += dynamic_cast<MultiRoom *>(it.operator->())->getMaxGuests();
                    } else {
                        localTotalSpaces += 1;
                    }
                    if (roomType == static_cast<RoomType>(2)) {
                        localOccupiedSpaces += it->getGuestCount();
                    } else if (it->isOccupied()) {
                        localOccupiedSpaces += 1;
                    }
                }
                std::advance(it, 1);
            }

            std::lock_guard<std::mutex> lock(mtx);
            results[index] = localTotalSpaces;
            results[index + 1] = localOccupiedSpaces;
        };

        int size = rooms.getSize();

        threads.emplace_back(processRooms, 0, size, 0, static_cast<RoomType>(0));
        threads.emplace_back(processRooms, 0, size, 2, static_cast<RoomType>(1));
        threads.emplace_back(processRooms, 0, size, 4, static_cast<RoomType>(2));

        for (auto &t: threads) {
            t.join();
        }

        totalSpaces = results[0] + results[2] + results[4];
        occupiedSpaces = results[1] + results[3] + results[5];

        if (totalSpaces == 0) {
            return 0.0;
        }

        return static_cast<double>(occupiedSpaces) / totalSpaces;
    }
};
