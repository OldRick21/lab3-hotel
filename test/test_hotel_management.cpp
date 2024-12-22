 #define CATCH_CONFIG_MAIN
 #include <catch2/catch_test_macros.hpp>
 #include "HotelManagement.hpp"
 #include "LuxuryRoom.hpp"
 #include "MultiRoom.hpp"
 #include "SingleRoom.hpp"
 #include <sstream>

 TEST_CASE("HotelManagement: Adding Rooms") {
     HotelManagement hotel;

     // Adding rooms
     hotel.addRoom(new LuxuryRoom(101, false, 2, 1, "2023-10-01", 5, 200.0));
     hotel.addRoom(new MultiRoom(102, false, 4, 0, {}, 150.0));
     hotel.addRoom(new SingleRoom(103, false, "2023-10-01", 3, 100.0));

     // Checking room count
     REQUIRE(hotel.getRooms().getSize() == 3);
 }

 TEST_CASE("HotelManagement: Registering Guests in Different Rooms") {
     HotelManagement hotel;

     // Adding rooms
     hotel.addRoom(new LuxuryRoom(101, false, 2, 1, "2023-10-01", 5, 200.0));
     hotel.addRoom(new MultiRoom(102, false, 4, 0, {}, 150.0));
     hotel.addRoom(new SingleRoom(103, false, "2023-10-01", 3, 100.0));

     // Registering guests
     hotel.registerGuest("Alice", 101, "2023-10-01", 5);
     hotel.registerGuest("Bob", 102);
     hotel.registerGuest("Charlie", 102);
     hotel.registerGuest("Dave", 103, "2023-10-01", 3);

     // Checking guest registration
     REQUIRE(hotel.getRoomsBegin()->isOccupied());
     REQUIRE(!(++hotel.getRoomsBegin())->isOccupied());
     REQUIRE((++(++hotel.getRoomsBegin()))->isOccupied());
 }

 TEST_CASE("HotelManagement: Registering Guests in Occupied Rooms") {
     HotelManagement hotel;

     // Adding rooms
     hotel.addRoom(new LuxuryRoom(101, false, 2, 1, "2023-10-01", 5, 200.0));
     hotel.addRoom(new SingleRoom(103, false, "2023-10-01", 3, 100.0));

     // Registering guests
     hotel.registerGuest("Alice", 101, "2023-10-01", 5);
     hotel.registerGuest("Dave", 103, "2023-10-01", 3);

     // Trying to register guests in occupied rooms
     hotel.registerGuest("Eve", 101, "2023-10-01", 5);
     hotel.registerGuest("Frank", 103, "2023-10-01", 3);

     // Checking guest registration
     REQUIRE(hotel.getRoomsBegin()->isOccupied());
     REQUIRE((++hotel.getRoomsBegin())->isOccupied());
 }

 TEST_CASE("HotelManagement: Removing Guests from MultiRoom") {
     HotelManagement hotel;

     // Adding rooms
     hotel.addRoom(new MultiRoom(102, false, 4, 0, {}, 150.0));

     // Registering guests
     hotel.registerGuest("Bob", 102);
     hotel.registerGuest("Charlie", 102);

     // Removing a guest
     hotel.removeGuest("Bob", 102);

     // Checking guest removal
     REQUIRE(hotel.getRoomsBegin()->getGuestCount() == 1);
 }

 TEST_CASE("HotelManagement: Removing Guests from Empty MultiRoom") {
     HotelManagement hotel;

     // Adding rooms
     hotel.addRoom(new MultiRoom(102, false, 4, 0, {}, 150.0));

     // Removing a guest from an empty room
     hotel.removeGuest("Bob", 102);

     // Checking guest removal
     REQUIRE(hotel.getRoomsBegin()->getGuestCount() == 0);
 }

 TEST_CASE("HotelManagement: Checking Out Guests from Different Rooms") {
     HotelManagement hotel;

     // Adding rooms
     hotel.addRoom(new LuxuryRoom(101, false, 2, 1, "2023-10-01", 5, 200.0));
     hotel.addRoom(new SingleRoom(103, false, "2023-10-01", 3, 100.0));

     // Registering guests
     hotel.registerGuest("Alice", 101, "2023-10-01", 5);
     hotel.registerGuest("Dave", 103, "2023-10-01", 3);

     // Checking out guests
     hotel.checkoutGuest(101);
     hotel.checkoutGuest(103);

     // Checking guest checkout
     REQUIRE(!hotel.getRoomsBegin()->isOccupied());
     REQUIRE(!(++hotel.getRoomsBegin())->isOccupied());
 }

 TEST_CASE("HotelManagement: Checking Out Guests from Empty Rooms") {
     HotelManagement hotel;

     // Adding rooms
     hotel.addRoom(new LuxuryRoom(101, false, 2, 1, "2023-10-01", 5, 200.0));
     hotel.addRoom(new SingleRoom(103, false, "2023-10-01", 3, 100.0));

     // Checking out guests from empty rooms
     hotel.checkoutGuest(101);
     hotel.checkoutGuest(103);

     // Checking guest checkout
     REQUIRE(!hotel.getRoomsBegin()->isOccupied());
     REQUIRE(!(++hotel.getRoomsBegin())->isOccupied());
 }

 TEST_CASE("HotelManagement: Listing Available Rooms") {
     HotelManagement hotel;

     // Adding rooms
     hotel.addRoom(new LuxuryRoom(101, false, 2, 1, "2023-10-01", 5, 200.0));
     hotel.addRoom(new MultiRoom(102, false, 4, 0, {}, 150.0));
     hotel.addRoom(new SingleRoom(103, false, "2023-10-01", 3, 100.0));

     // Listing available rooms
     std::stringstream buffer;
     std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
     hotel.listAvailableRooms();
     std::cout.rdbuf(old);

     std::string output = buffer.str();
     REQUIRE(output == "Available rooms:\nRoom 101 (Luxury)\nRoom 103 (Single)\n");
 }

 TEST_CASE("HotelManagement: Listing MultiRooms") {
     HotelManagement hotel;

     // Adding rooms
     hotel.addRoom(new MultiRoom(102, false, 4, 0, {}, 150.0));
     hotel.addRoom(new MultiRoom(104, false, 3, 0, {}, 120.0));

     // Listing multi-rooms
     std::stringstream buffer;
     std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
     hotel.listMultiRooms();
     std::cout.rdbuf(old);

     std::string output = buffer.str();
     REQUIRE(output == "MultiRooms and their occupancy:\nRoom 102 (Multi): Empty\nRoom 104 (Multi): Empty\n");
 }

 TEST_CASE("HotelManagement: Listing Full Rooms") {
     HotelManagement hotel;

     // Adding rooms
     hotel.addRoom(new LuxuryRoom(101, false, 2, 1, "2023-10-01", 5, 200.0));
     hotel.addRoom(new SingleRoom(103, false, "2023-10-01", 3, 100.0));

     // Registering guests
     hotel.registerGuest("Alice", 101, "2023-10-01", 5);
     hotel.registerGuest("Dave", 103, "2023-10-01", 3);

     // Listing full rooms
     std::stringstream buffer;
     std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
     hotel.listFullRooms();
     std::cout.rdbuf(old);

     std::string output = buffer.str();
     REQUIRE(output == "Full rooms:\nRoom 101 (Luxury)\n  Guest: Alice\nRoom 103 (Single)\n  Guest: Dave\n");
 }

 TEST_CASE("HotelManagement: Calculating Occupancy") {
     HotelManagement hotel;

     // Adding rooms
     hotel.addRoom(new LuxuryRoom(101, false, 2, 1, "2023-10-01", 5, 200.0));
     hotel.addRoom(new MultiRoom(102, false, 4, 0, {}, 150.0));
     hotel.addRoom(new SingleRoom(103, false, "2023-10-01", 3, 100.0));

     // Registering guests
     hotel.registerGuest("Alice", 101, "2023-10-01", 5);
     hotel.registerGuest("Bob", 102);
     hotel.registerGuest("Charlie", 102);
     hotel.registerGuest("Dave", 103, "2023-10-01", 3);

     // Calculating occupancy
     REQUIRE((int) (hotel.calculateOccupancy() * 100000) == (int) (0.6666666667 * 100000));
 }

 TEST_CASE("HotelManagement: Calculating Occupancy with Warning") {
     HotelManagement hotel;

     // Adding rooms
     hotel.addRoom(new LuxuryRoom(101, false, 2, 1, "2023-10-01", 5, 200.0));
     hotel.addRoom(new MultiRoom(102, false, 4, 0, {}, 150.0));
     hotel.addRoom(new SingleRoom(103, false, "2023-10-01", 3, 100.0));

     // Registering guests
     hotel.registerGuest("Alice", 101, "2023-10-01", 5);
     hotel.registerGuest("Bob", 102);
     hotel.registerGuest("Charlie", 102);
     hotel.registerGuest("Dave", 103, "2023-10-01", 3);
     hotel.registerGuest("Eve", 102);
     hotel.registerGuest("Frank", 102);

     // Calculating occupancy
     std::stringstream buffer;
     std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
     double occupancyRate = hotel.calculateOccupancy();
     std::cout.rdbuf(old);

     double tmp = 0.3;

     std::string output = buffer.str();
     REQUIRE(occupancyRate > tmp);
 }

 TEST_CASE("LuxuryRoom Constructor") {
     LuxuryRoom room(101, false, 2, 1, "2023-10-01", 5, 200.0);
     REQUIRE(room.getRoomNumber() == 101);
     REQUIRE(room.isOccupied() == false);
     REQUIRE(room.getGuestCount() == 1);
     REQUIRE(room.getType() == static_cast<RoomType>(0));
 }

 TEST_CASE("LuxuryRoom displayInfo") {
     LuxuryRoom room(101, false, 2, 1, "2023-10-01", 5, 200.0);
     std::stringstream buffer;
     std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
     room.displayInfo();
     std::cout.rdbuf(old);
     std::string output = buffer.str();
     REQUIRE(output == "Luxury Room 101:\nOccupied: No\nNumber of Rooms: 2\nNumber of Guests: 1\nRegistration Date: 2023-10-01\nDays of Stay: 5\nDaily Rate: 200\n");
 }

 TEST_CASE("LuxuryRoom occupyRoom") {
     LuxuryRoom room(101, false, 2, 1, "2023-10-01", 5, 200.0);
     room.occupyRoom("2023-10-05", 7);
     REQUIRE(room.isOccupied() == true);
     REQUIRE(room.getGuestCount() == 1);
     REQUIRE(room.getRoomNumber() == 101);
 }

 TEST_CASE("LuxuryRoom vacateRoom") {
     LuxuryRoom room(101, true, 2, 1, "2023-10-01", 5, 200.0);
     room.vacateRoom();
     REQUIRE(room.isOccupied() == false);
     REQUIRE(room.getGuestCount() == 0);
     REQUIRE(room.getRoomNumber() == 101);
 }

 TEST_CASE("LuxuryRoom getGuestName and setName") {
     LuxuryRoom room(101, false, 2, 1, "2023-10-01", 5, 200.0);
     room.setName("John Doe");
     REQUIRE(room.getGuestName() == "John Doe");
 }

 TEST_CASE("LuxuryRoom operator==") {
     LuxuryRoom room1(101, false, 2, 1, "2023-10-01", 5, 200.0);
     LuxuryRoom room2(101, true, 2, 1, "2023-10-01", 5, 200.0);
     LuxuryRoom room3(102, false, 2, 1, "2023-10-01", 5, 200.0);
     REQUIRE(room1 == room2);
     REQUIRE_FALSE(room1 == room3);
 }

 TEST_CASE("LuxuryRoom operator<") {
     LuxuryRoom room1(101, false, 2, 1, "2023-10-01", 5, 200.0);
     LuxuryRoom room2(102, false, 2, 1, "2023-10-01", 5, 200.0);
     REQUIRE(room1 < room2);
     REQUIRE_FALSE(room2 < room1);
 }

 TEST_CASE("LuxuryRoom operator>") {
     LuxuryRoom room1(101, false, 2, 1, "2023-10-01", 5, 200.0);
     LuxuryRoom room2(102, false, 2, 1, "2023-10-01", 5, 200.0);
     REQUIRE(room2 > room1);
     REQUIRE_FALSE(room1 > room2);
 }

 TEST_CASE("MultiRoom Constructor") {
     std::vector<std::string> guests = {"Alice", "Bob"};
     MultiRoom room(101, false, 4, 2, guests, 150.0);
     REQUIRE(room.getRoomNumber() == 101);
     REQUIRE(room.isOccupied() == false);
     REQUIRE(room.getGuestCount() == 2);
     REQUIRE(room.getType() == static_cast<RoomType>(2));
     REQUIRE(room.getMaxGuests() == 4);
 }

 TEST_CASE("MultiRoom displayInfo") {
     std::vector<std::string> guests = {"Alice", "Bob"};
     MultiRoom room(101, false, 4, 2, guests, 150.0);
     std::stringstream buffer;
     std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
     room.displayInfo();
     std::cout.rdbuf(old);
     std::string output = buffer.str();
     REQUIRE(output == "Multi Room 101:\nOccupied: No\nTotal Spaces: 4\nOccupied Spaces: 2\nGuest Info:\nDaily Rate: 150\n");
 }

 TEST_CASE("MultiRoom occupyRoom") {
     std::vector<std::string> guests = {"Alice", "Bob"};
     MultiRoom room(101, false, 4, 2, guests, 150.0);
     room.occupyRoom("2023-10-05", 7);
     REQUIRE(room.isOccupied() == true);
     REQUIRE(room.getGuestCount() == 3);
     REQUIRE(room.getRoomNumber() == 101);
 }

 TEST_CASE("MultiRoom vacateRoom") {
     std::vector<std::string> guests = {"Alice", "Bob"};
     MultiRoom room(101, true, 4, 2, guests, 150.0);
     room.vacateRoom();
     REQUIRE(room.isOccupied() == false);
     REQUIRE(room.getGuestCount() == 0);
     REQUIRE(room.getRoomNumber() == 101);
 }

 TEST_CASE("MultiRoom occupyPart") {
     std::vector<std::string> guests = {"Alice", "Bob"};
     MultiRoom room(101, false, 4, 2, guests, 150.0);
     room.occupyPart("2023-10-05", 7);
     REQUIRE(room.isOccupied() == true);
     REQUIRE(room.getGuestCount() == 3);
     REQUIRE(room.getRoomNumber() == 101);
 }


 TEST_CASE("MultiRoom isEmpty") {
     std::vector<std::string> guests = {"Alice", "Bob"};
     MultiRoom room(101, false, 4, 2, guests, 150.0);
     REQUIRE(room.isEmpty() == false);
 }

 TEST_CASE("MultiRoom getGuests") {
     std::vector<std::string> guests = {"Alice", "Bob"};
     MultiRoom room(101, false, 4, 2, guests, 150.0);
     REQUIRE(room.getGuests() == guests);
 }

 TEST_CASE("MultiRoom vacatePart") {
     std::vector<std::string> guests = {"Alice", "Bob"};
     MultiRoom room(101, false, 4, 2, guests, 150.0);
     room.occupyPart("2023-10-05", 7);
     room.vacatePart();
     REQUIRE(room.getGuestCount() == 2);
     REQUIRE(room.isOccupied() == true);
 }

 TEST_CASE("MultiRoom addGuest") {
     std::vector<std::string> guests = {"Alice", "Bob"};
     MultiRoom room(101, false, 4, 2, guests, 150.0);
     REQUIRE(room.addGuest("Charlie") == true);
     REQUIRE(room.getGuestCount() == 3);
 }

 TEST_CASE("MultiRoom removeGuest") {
     std::vector<std::string> guests = {"Alice", "Bob"};
     MultiRoom room(101, false, 4, 2, guests, 150.0);
     REQUIRE(room.removeGuest("Alice") == true);
     REQUIRE(room.getGuestCount() == 1);
 }

 TEST_CASE("MultiRoom clearGuests") {
     std::vector<std::string> guests = {"Alice", "Bob"};
     MultiRoom room(101, false, 4, 2, guests, 150.0);
     room.clearGuests();
     REQUIRE(room.getGuestCount() == 0);
 }

 TEST_CASE("MultiRoom operator==") {
     std::vector<std::string> guests = {"Alice", "Bob"};
     MultiRoom room1(101, false, 4, 2, guests, 150.0);
     MultiRoom room2(101, true, 4, 2, guests, 150.0);
     MultiRoom room3(102, false, 4, 2, guests, 150.0);
     REQUIRE(room1 == room2);
     REQUIRE_FALSE(room1 == room3);
 }

 TEST_CASE("MultiRoom operator<") {
     std::vector<std::string> guests = {"Alice", "Bob"};
     MultiRoom room1(101, false, 4, 2, guests, 150.0);
     MultiRoom room2(102, false, 4, 2, guests, 150.0);
     REQUIRE(room1 < room2);
     REQUIRE_FALSE(room2 < room1);
 }

 TEST_CASE("MultiRoom operator>") {
     std::vector<std::string> guests = {"Alice", "Bob"};
     MultiRoom room1(101, false, 4, 2, guests, 150.0);
     MultiRoom room2(102, false, 4, 2, guests, 150.0);
     REQUIRE(room2 > room1);
     REQUIRE_FALSE(room1 > room2);
 }

 TEST_CASE("SingleRoom Constructor") {
     SingleRoom room(101, false, "2023-10-01", 5, 100.0);
     REQUIRE(room.getRoomNumber() == 101);
     REQUIRE(room.isOccupied() == false);
     REQUIRE(room.getGuestCount() == 0);
     REQUIRE(room.getType() == static_cast<RoomType>(1));
 }

 TEST_CASE("SingleRoom displayInfo") {
     SingleRoom room(101, false, "2023-10-01", 5, 100.0);
     std::stringstream buffer;
     std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
     room.displayInfo();
     std::cout.rdbuf(old);
     std::string output = buffer.str();
     REQUIRE(output == "Single Room 101:\nOccupied: No\nRegistration Date: 2023-10-01\nDays of Stay: 5\nDaily Rate: 100\n");
 }

 TEST_CASE("SingleRoom occupyRoom") {
     SingleRoom room(101, false, "2023-10-01", 5, 100.0);
     room.occupyRoom("2023-10-05", 7);
     REQUIRE(room.isOccupied() == true);
     REQUIRE(room.getGuestCount() == 1);
     REQUIRE(room.getRoomNumber() == 101);
 }

 TEST_CASE("SingleRoom vacateRoom") {
     SingleRoom room(101, true, "2023-10-01", 5, 100.0);
     room.vacateRoom();
     REQUIRE(room.isOccupied() == false);
     REQUIRE(room.getGuestCount() == 0);
     REQUIRE(room.getRoomNumber() == 101);
 }

 TEST_CASE("SingleRoom getGuestName and setName") {
     SingleRoom room(101, false, "2023-10-01", 5, 100.0);
     room.setName("John Doe");
     REQUIRE(room.getGuestName() == "John Doe");
 }

 TEST_CASE("SingleRoom operator==") {
     SingleRoom room1(101, false, "2023-10-01", 5, 100.0);
     SingleRoom room2(101, true, "2023-10-01", 5, 100.0);
     SingleRoom room3(102, false, "2023-10-01", 5, 100.0);
     REQUIRE(room1 == room2);
     REQUIRE_FALSE(room1 == room3);
 }

 TEST_CASE("SingleRoom operator<") {
     SingleRoom room1(101, false, "2023-10-01", 5, 100.0);
     SingleRoom room2(102, false, "2023-10-01", 5, 100.0);
     REQUIRE(room1 < room2);
     REQUIRE_FALSE(room2 < room1);
 }

 TEST_CASE("SingleRoom operator>") {
     SingleRoom room1(101, false, "2023-10-01", 5, 100.0);
     SingleRoom room2(102, false, "2023-10-01", 5, 100.0);
     REQUIRE(room2 > room1);
     REQUIRE_FALSE(room1 > room2);
 }

 TEST_CASE("OrderedTable Constructor and Destructor") {
     OrderedTable<int> table(5);
     REQUIRE(table.getSize() == 0);
 }

 TEST_CASE("OrderedTable Insert") {
     OrderedTable<int> table;
     int* value1 = new int(10);
     int* value2 = new int(5);
     int* value3 = new int(15);

     table.insert(value1);
     table.insert(value2);
     table.insert(value3);

     REQUIRE(table.getSize() == 3);

     std::stringstream buffer;
     std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
     table.print();
     std::cout.rdbuf(old);
     std::string output = buffer.str();
     REQUIRE(output == "5 10 15 \n");
 }

 TEST_CASE("OrderedTable Search") {
     OrderedTable<int> table;
     int* value1 = new int(10);
     int* value2 = new int(5);
     int* value3 = new int(15);

     table.insert(value1);
     table.insert(value2);
     table.insert(value3);

     REQUIRE(table.search(10) == true);
     REQUIRE(table.search(5) == true);
     REQUIRE(table.search(15) == true);
     REQUIRE(table.search(20) == false);
 }

 TEST_CASE("OrderedTable Remove") {
     OrderedTable<int> table;
     int* value1 = new int(10);
     int* value2 = new int(5);
     int* value3 = new int(15);

     table.insert(value1);
     table.insert(value2);
     table.insert(value3);

     REQUIRE(table.remove(value2) == true);
     REQUIRE(table.getSize() == 2);
     REQUIRE(table.remove(value1) == true);
     REQUIRE(table.getSize() == 1);
     REQUIRE(table.remove(value3) == true);
     REQUIRE(table.getSize() == 0);

 }

 TEST_CASE("OrderedTable Iterator") {
     OrderedTable<int> table;
     int* value1 = new int(10);
     int* value2 = new int(5);
     int* value3 = new int(15);

     table.insert(value1);
     table.insert(value2);
     table.insert(value3);

     auto it = table.begin();
     REQUIRE(*it == 5);
     ++it;
     REQUIRE(*it == 10);
     ++it;
     REQUIRE(*it == 15);
     ++it;
     REQUIRE(it == table.end());

 }

 TEST_CASE("OrderedTable Resize") {
     OrderedTable<int> table(2);
     int* value1 = new int(10);
     int* value2 = new int(5);
     int* value3 = new int(15);

     table.insert(value1);
     table.insert(value2);
     table.insert(value3);

     REQUIRE(table.getSize() == 3);

     std::stringstream buffer;
     std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
     table.print();
     std::cout.rdbuf(old);
     std::string output = buffer.str();
     REQUIRE(output == "5 10 15 \n");

 }