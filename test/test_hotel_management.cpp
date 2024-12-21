// #define CATCH_CONFIG_MAIN
// #include <catch2/catch_test_macros.hpp>
// #include "OrderedTable.hpp"
// #include "LuxuryRoom.hpp"
// #include "SingleRoom.hpp"
// #include "MultiRoom.hpp"
// #include "OccupancyIterator.hpp"

// // Тест для проверки добавления номера
// TEST_CASE("AddElement") {
//     OrderedTable<Room*> roomTable;
//     roomTable.addElement(101, new LuxuryRoom(false, 2, 0, "2023-10-01", 5, 200.0));
//     auto room = roomTable.findElement(101);
//     REQUIRE(room != nullptr);
//     REQUIRE(room->roomNumber == 101);
//     delete room->roomDescriptor;
// }

// // Тест для проверки поиска номера
// TEST_CASE("FindElement") {
//     OrderedTable<Room*> roomTable;
//     roomTable.addElement(101, new LuxuryRoom(false, 2, 0, "2023-10-01", 5, 200.0));
//     auto room = roomTable.findElement(101);
//     REQUIRE(room != nullptr);
//     REQUIRE(room->roomNumber == 101);
//     delete room->roomDescriptor;
// }

// // Тест для проверки удаления номера
// TEST_CASE("RemoveElement") {
//     OrderedTable<Room*> roomTable;
//     roomTable.addElement(101, new LuxuryRoom(false, 2, 0, "2023-10-01", 5, 200.0));
//     roomTable.removeElement(101);
//     auto room = roomTable.findElement(101);
//     REQUIRE(room == nullptr);
// }

// // Тест для проверки регистрации гостя
// TEST_CASE("RegisterGuest") {
//     OrderedTable<Room*> roomTable;
//     roomTable.addElement(101, new LuxuryRoom(false, 2, 0, "2023-10-01", 5, 200.0));
//     auto room = roomTable.findElement(101);
//     REQUIRE(room != nullptr);
//     room->roomDescriptor->occupyRoom();
//     REQUIRE(room->roomDescriptor->isOccupied());
//     delete room->roomDescriptor;
// }

// // Тест для проверки освобождения номера
// TEST_CASE("FreeRoom") {
//     OrderedTable<Room*> roomTable;
//     roomTable.addElement(101, new LuxuryRoom(false, 2, 0, "2023-10-01", 5, 200.0));
//     auto room = roomTable.findElement(101);
//     REQUIRE(room != nullptr);
//     room->roomDescriptor->occupyRoom();
//     REQUIRE(room->roomDescriptor->isOccupied());
//     room->roomDescriptor->freeRoom();
//     REQUIRE(!room->roomDescriptor->isOccupied());
//     delete room->roomDescriptor;
// }

// // Тест для проверки вывода информации о свободных номерах
// TEST_CASE("DisplayFreeRooms") {
//     OrderedTable<Room*> roomTable;
//     roomTable.addElement(101, new LuxuryRoom(false, 2, 0, "2023-10-01", 5, 200.0));
//     roomTable.addElement(102, new SingleRoom(false, "2023-10-02", 3, 100.0));
//     roomTable.addElement(103, new MultiRoom(false, 4, 0, {}, 50.0));

//     bool hasFreeRooms = false;
//     for (const auto& elem : roomTable.getTable()) {
//         if (!elem.roomDescriptor->isOccupied()) {
//             hasFreeRooms = true;
//             break;
//         }
//     }
//     REQUIRE(hasFreeRooms);

//     for (const auto& elem : roomTable.getTable()) {
//         delete elem.roomDescriptor;
//     }
// }
