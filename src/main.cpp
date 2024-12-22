#include "HotelManagement.hpp"

void showMenu() {
    std::cout << "Hotel Management System" << std::endl;
    std::cout << "1. Register Guest in Single/Luxury Room" << std::endl;
    std::cout << "2. Checkout Guest from Single/Luxury Room" << std::endl;
    std::cout << "3. List Available Single/Luxury Rooms" << std::endl;
    std::cout << "4. Calculate Occupancy" << std::endl;
    std::cout << "5. Register Guest in MultiRoom" << std::endl;
    std::cout << "6. Remove Guest from MultiRoom" << std::endl;
    std::cout << "7. List MultiRooms and their occupancy" << std::endl;
    std::cout << "8. List Full Rooms and Guest Names" << std::endl;
    std::cout << "9. Exit" << std::endl;
    std::cout << "10. Eagles" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    HotelManagement hotel1;

    for (int i = 1; i <= 100; i++) {
        bool occupied1 = i <= 25;  
        bool occupied2 = i <= 50;  
        hotel1.addRoom(new SingleRoom(1001 + i, occupied1, "", 0, 100.0));
        hotel1.addRoom(new LuxuryRoom(2001 + i, occupied2, 2, 4, "", 0, 200.0));
        hotel1.addRoom(new MultiRoom(3001 + i, true, 4, 1, {}, 150.0));
    }
//
//    std::cout << (25 + 50 + 100)/(100.0 + 100.0 + 400.0) << std::endl;
//
//    std::cout << hotel1.calculateOccupancy();

    HotelManagement hotel;

    
    hotel.addRoom(new SingleRoom(101, false, "", 0, 100.0));
    hotel.addRoom(new LuxuryRoom(201, false, 2, 4, "", 0, 200.0));
    hotel.addRoom(new MultiRoom(301, false, 4, 0, {}, 150.0));

    int choice;
    std::string guestName, registrationDate;
    int roomNumber, days;

    while (true) {
        showMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Invalid input. Please enter a number between 1 and 10." << std::endl;
            continue;
        }

        switch (choice) {
            case 1:
                std::cout << "Enter guest name: ";
                std::cin.ignore();
                std::getline(std::cin, guestName);
                std::cout << "Enter room number: ";
                std::cin >> roomNumber;
                std::cout << "Enter registration date: ";
                std::cin.ignore();
                std::getline(std::cin, registrationDate);
                std::cout << "Enter number of days: ";
                std::cin >> days;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input for number of days. Please enter a valid number." << std::endl;
                    break;
                }
                hotel.registerGuest(guestName, roomNumber, registrationDate, days);
                break;
            case 2:
                std::cout << "Enter room number: ";
                std::cin >> roomNumber;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input for room number. Please enter a valid number." << std::endl;
                    break;
                }
                hotel.checkoutGuest(roomNumber);
                break;
            case 3:
                hotel.listAvailableRooms();
                break;
            case 4:
                std::cout << "Hotel occupancy: " << hotel.calculateOccupancy() * 100 << "%" << std::endl;
                break;
            case 5:
                std::cout << "Enter guest name: ";
                std::cin.ignore();
                std::getline(std::cin, guestName);
                std::cout << "Enter room number: ";
                std::cin >> roomNumber;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input for room number. Please enter a valid number." << std::endl;
                    break;
                }
                hotel.registerGuest(guestName, roomNumber);
                break;
            case 6:
                std::cout << "Enter guest name: ";
                std::cin.ignore();
                std::getline(std::cin, guestName);
                std::cout << "Enter room number: ";
                std::cin >> roomNumber;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input for room number. Please enter a valid number." << std::endl;
                    break;
                }
                hotel.removeGuest(guestName, roomNumber);
                break;
            case 7:
                hotel.listMultiRooms();
                break;
            case 8:
                hotel.listFullRooms();
                break;
            case 9:
                std::cout << "Exiting..." << std::endl;
                return 0;
            case 10:
                std::cout << "Welcome to the Hotel California" << std::endl;
                std::cout << "Such a lovely place (Such a lovely place)" << std::endl;
                std::cout << "Such a lovely face" << std::endl;
                std::cout << "Plenty of room at the Hotel California" << std::endl;
                std::cout << "Any time of year (Any time of year)" << std::endl;
                std::cout << "You can find it here" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
