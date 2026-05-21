#include <iostream>
using namespace std;

int main()
{
    int number{};
    cout << "Enter an any number: ";
    while (!(cin >> number)) {
        cout << "Its a letter. Try enter number\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    if (number % 2 == 1) {
        cout << "Odd number\n";
    }
    else {
        cout << "Even number\n";
    }
    return 0;
}