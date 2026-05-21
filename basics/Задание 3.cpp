#include <iostream>

int main() {
	int shift_duration = 480;
	int time_to_order = 2;
	int time_to_ready = 4;
	std::cout << "This program will calculate how many customers the cashier can serve during the shift.\n";
	std::cout << "--------------------------------------------------------------------------------------\n";
	std::cout << "A cashier can serve up to " << shift_duration / (time_to_order + time_to_ready) << " customers in one shift\n";
	return 0;
}