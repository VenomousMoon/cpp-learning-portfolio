#include <iostream>
#include <limits>

static int getSum(const int& one, const int& two) {
	return one + two;
}

int main() 
{
	int num1{};
	int num2{};

	while (true) {
		std::cout << "Enter first num: ";
		std::cin >> num1;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Incorrect entering, try again: ";
		}
		else {
			break;
		}
	}
	
	while (true) {
		std::cout << "Enter second num: ";
		std::cin >> num2;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Incorrect entering, try again: ";
		}
		else {
			break;
		}
	}
	int amount = getSum(num1, num2);
	std::cout << "The amount is " << amount << "\n";
	return 0;
}