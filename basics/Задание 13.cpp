#include <iostream>
using namespace std;

int main()
{
	int number{};
	cout << "Enter any number: ";
	while (!(cin >> number)) {
		cerr << "Its letter or incorrect meaning. Enter thw number: ";
		cin.clear();
		cin.ignore(100000, '\n');
	}
	
	int sum{};
	for (int count{}; number != 0; count++) {
		sum += number % 10;
		number /= 10;
	}
	cout << "Sum of the numbers is: " << sum << endl;
	return 0;

}