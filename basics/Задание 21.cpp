#include <iostream>
#include <string>
#include <cctype>

static bool isValidTime(const std::string& str) {
    if (str.length() != 5) return false;
    if (str[2] != ':') return false;
    for (char c : str) {
        if (c == ' ') {
            return false;
        }
    }
    for (int i{}; i < 5; i++) {
        if (i == 2) continue;
        if (!std::isdigit(str[i])) return false;
    }
    int hours = std::stoi(str.substr(0, 2));
    if (hours < 0 || hours > 23) return false;

    int minutes = std::stoi(str.substr(3, 2));
    if (minutes < 0 || minutes > 59) return false;

    return true;
}

int main()
{
    std::string departureTime{}, arrivalTime{};

    std::cout << "Enter departure time: ";
    while (true) {
        std::getline(std::cin, departureTime);
        if (isValidTime(departureTime)) {
            break;
        }
        std::cout << "Incorrect time, time must be in format (HH:MM). Enter again: ";
    }

    std::cout << "Enter arrival time: ";
    while (true) {
        std::getline(std::cin, arrivalTime);
        if (isValidTime(arrivalTime)) {
            break;
        }
        std::cout << "Incorrect time, time must be in format (HH:MM). Enter again: ";
    }
    
    int departureHours = std::stoi(departureTime.substr(0, 2));
    int departureMinutes = std::stoi(departureTime.substr(3, 2));

    int arrivalHours = std::stoi(arrivalTime.substr(0, 2));
    int arrivalMinutes = std::stoi(arrivalTime.substr(3, 2));

    int departureTotal = departureHours * 60 + departureMinutes;
    int arrivalTotal = arrivalHours * 60 + arrivalMinutes;

    int difference = arrivalTotal - departureTotal;
    if (difference < 0) {
        difference += 1440;
    }

    int hours = difference / 60;
    int minutes = difference % 60;

    if (difference == 0) {
        std::cerr << "Incorrect date, the difference cannot be zero, restart the program and try again\n";
        return 1;
    } 
    else if (hours == 0) {
        std::cout << "Travel time: " << minutes << " minutes\n";
    }
    else if (minutes == 0) {
        std::cout << "Travel time: " << hours << " hours\n";
    } 
    else {
        std::cout << "Travel time: " << hours << " hours and " << minutes << " minutes\n";
    }
    return 0;
}
    