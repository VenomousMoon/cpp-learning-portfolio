#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <cmath>

static bool isValidNumber(const std::string& str) {
	if (str.empty()) return false;
	for (char c : str) {
		if (!std::isdigit(c)) {
			return false;
		}
	}
	return true;
}

int main() 
{
	std::string forceS{};
	std::string massS{};
	std::string timeS{};

	std::cout << "Enter force (N): ";
	
	while (true) {
		std::cin >> forceS;
		if (isValidNumber(forceS)) {
			break;
		}
		std::cout << "Enter a positive number or dont use letters. Try again: ";
	}

	std::cout << "Enter mass (kg): ";

	while (true) {
		std::cin >> massS;
		if (isValidNumber(massS)) {
			break;
		}
		std::cout << "Enter a positive number or dont use letters. Try again: ";
	}

	std::cout << "Enter time (seconds): ";

	while (true) {
		std::cin >> timeS;
		if (isValidNumber(timeS)) {
			break;
		}
		std::cout << "Enter a positive number or dont use letters. Try again: ";
	}

	double force = std::stod(forceS);
	double mass = std::stod(massS);
	double time = std::stod(timeS);

	if (mass == 0) {
		std::cerr << "You cannot divide by 0, restart the program and try again" << std::endl;
		return 1;
	}

	std::cout << std::fixed << std::setprecision(2);
	std::cout << "The path is: " << (force * std::pow(time, 2)) / (2 * mass) << std::endl;
	return 0;
}