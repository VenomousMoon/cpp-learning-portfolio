#include <iostream>
#include <string>
#include <limits>

static double getDistance(const double a, const double v, const double t) {
	return (v * t) + (a * (t * t)) / 2;
}
static double getValidDouble(const std::string& str, bool positiveOnly = false) {
	double number{};

	while (true) {
		std::cout << str;
		std::cin >> number;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Enter the number\n";
		}
		else if (positiveOnly && number < 0) {
			std::cout << "Enter the positive number\n";
		}
		else {
			return number;
		}
	}
}

int main()
{
	double acceleration = getValidDouble("Enter the acceleration: ");
	double initialSpeed = getValidDouble("Enter the speed: ");
	double time = getValidDouble("Enter the time: ");
    double answer = getDistance(acceleration, initialSpeed, time);

	std::cout << "Distance is: " << answer << "\n";
	return 0;
}