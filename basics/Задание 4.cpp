#include <iostream>

int main() {
	int amount_in_receipt = 4000000;
	int entrance_in_house = 10;
	int apartments_in_entrance = 40;

	std::cout << "Each apartment must pay: " << amount_in_receipt / (entrance_in_house * apartments_in_entrance) << "\n";

	return 0;
}