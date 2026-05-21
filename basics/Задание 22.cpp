#include <iostream>
#include <string>
#include <cctype>

static bool isValidNumber(const std::string& str) {
	if (str.empty()) return false;
	for (char c : str) {
		if (!isdigit(c)) {
			return false;
		}
	}
	return true;
}

int main() 
{
	std::string firstNum{};
	std::string secondNum{};

	std::cout << "Enter any positive number: ";

	while (true) {
		std::cin >> firstNum;
		if (isValidNumber(firstNum)) {
			break;
		}
		std::cout << "Enter positive number only, without letters\n";
	}

	std::cout << "Enter any positive number: ";

	while (true) {
		std::cin >> secondNum;
		if (isValidNumber(secondNum)) {
			break;
		}
		std::cout << "Enter positive number only, without letters\n";
	}

	int firstNumber = stoi(firstNum);
	int secondNumber = stoi(secondNum);

	int max = (firstNumber > secondNumber) ? firstNumber : secondNumber;

	std::cout << "The largest number is " << max << std::endl;
	return 0;
}
