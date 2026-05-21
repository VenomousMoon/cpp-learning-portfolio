#include <iostream>
#include <string>
#include <vector>
#include <fstream> 
#include <limits>

int main()
{
    std::vector<std::string> myGarage{};

    int choice = -1;
    std::string cars{};

    std::ifstream inputFile("garage.txt");
    if (inputFile.is_open()) {
        while (std::getline(inputFile, cars)) {
            if (!cars.empty()) {
                myGarage.push_back(cars);
            }
        }
        inputFile.close();
    }
    while (choice != 2) {
        std::cout << "\nWhat do you want to do?\n";
        std::cout << "0 - Show the cars\n";
        std::cout << "1 - Add new car\n";
        std::cout << "2 - Save and exit\n";
        std::cout << "Your choice: ";
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = -1;
            std::cout << "Incorrect command, try again. Without letters and using 0 or 1 or 2 (0 - Show the cars, 1 - Add new car, 2 - save and exit)\n";
            continue;
        }
        if (choice == 0) {
            if (myGarage.empty()) {
                std::cout << "Your garage is empty\n";
            }
            else {
                std::cout << "\nNow in your garage: " << "\n";
                int count{};
                for (const std::string& car : myGarage) {
                    std::cout << ++count << "." << car << "\n";
                }
            }
        }
        else if (choice == 1) {
            std::cin.ignore();
            while (true) {
                std::cout << "\nAdd the new car (press enter without typing to stop): ";
                std::string newCar;
                std::getline(std::cin, newCar);
                if (newCar.empty()) {
                    break;
                }
                myGarage.push_back(newCar);
                std::cout << "Total added: " << myGarage.size() << "\n";
            }
            std::cout << "Cars added\n";
        }
        else if (choice == 2) {
            break;
        }
    }
    std::ofstream outputFile("garage.txt");
    if (outputFile.is_open()) {
        for (const std::string& car : myGarage) {
            outputFile << car << std::endl;
        }
        outputFile.close();
        std::cout << "Data saved\n";
    }
    return 0;
}

