#include <iostream>
using namespace std;

int main()
{
    int firstNumber{};
    int secondNumber{};
    int num{};

    cout << "Enter first number: ";
    while (!(cin >> firstNumber)) {
        cerr << "Enter a number, you entered letter\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Enter second number: ";
    while (!(cin >> secondNumber)) {
        cerr << "Enter a number, you entered letter\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    if (firstNumber % secondNumber == 0) {
        cout << "Yes, " << firstNumber << " divides by " << secondNumber << " without remainder!\n";
    }
    else if (secondNumber % firstNumber == 0) {
        cout << "Yes, " << secondNumber << " divides by " << firstNumber << " without remainder!\n";
    }
    else {
        cout << "No, numbers are not divisible without remainder!\n";
    }
    return 0;
}
