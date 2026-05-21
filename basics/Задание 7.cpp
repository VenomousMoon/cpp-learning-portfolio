#include <iostream>
using namespace std;

int main()
{
    double firstNumber{};
    double secondNumber{};
    cout << "Enter first number: ";
    cin >> firstNumber;
    cout << "Enter second number: ";
    cin >> secondNumber;
    if (firstNumber > secondNumber) {
        cout << "Second number (" << secondNumber << ") less than first number (" << firstNumber << ")";
    }
    else if (firstNumber == secondNumber) {
        cout << "The numbers are equal\n";
    }
    else {
        cout << "First number (" << firstNumber << ") less than second number (" << secondNumber << ")";
    }
    return 0;
}
