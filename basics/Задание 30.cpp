#include <iostream>
#include <cctype>
#include <string>
#include <limits>

static bool isValidNumber(const std::string& str) {
	if (str.empty()) return false;

	int start{};
	if (str[0] == '-') {
		if (str.length() == 1) return false;
		start = 1;
	}
	for (int i = start; i < str.length(); ++i) {
		if (!isdigit(str[i])) {
			return false;
		}
	}
	return true;
}
		
static int parsedNumber(const std::string& num) {
	int result{};
	int start{};
	bool negative = false;

	if (num[0] == '-') {
		negative = true;
		start = 1;
	}
	for (int i = start; i < num.length(); ++i) {
		result = result * 10 + (num[i] - '0');
	}
	return negative ? -result : result;
}

int main() 
{
	std::string number{};
	while (true) {
		std::cout << "Enter the number: ";
		std::getline(std::cin, number);
		if (isValidNumber(number)) {
			break;
		}
		else {
			std::cout << "Incorrect input, try without spaces\n";
		}
	}

	std::cout << "Parsed number is: " << parsedNumber(number) << "\n";
	return 0;
}
