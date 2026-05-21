#include <iostream>
using namespace std;

int main()
{
    double firstNumber{};
    double secondNumber{};
    double correctAmount{};
    double amount{}; 

    cout << "Enter first number: ";
    while (!(cin >> firstNumber)) {
        cout << "Enter first number, not letter. Try again\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Enter second number: ";
    while (!(cin >> secondNumber)) {
        cout << "Enter second number, not letter\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    cout << "\n";

    correctAmount = firstNumber + secondNumber;

    cout << "Enter amount of these numbers: ";

    while (true) {
        cin >> amount;

        if (cin.fail()) {
            cout << "Enter a number. Not letter\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        if (amount == correctAmount) {
            cout << "Its correct amount\n";
            break;
        }
        else {
            cout << "Its incorrect. Try again\n";
        }
    }
    return 0;
}