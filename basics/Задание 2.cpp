#include <iostream>

int main() {
	int product_cost = 100000;
	int delivery_cost = 10000;
	int discount = 13000;

	int total_price = product_cost + delivery_cost - discount;

	std::cout << "Full price will be: " << total_price << "\n";
	return 0;
}