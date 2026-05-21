#include <iostream>
using namespace std; // проект учебный, можно и namespace

int main()
{
    int buckwheat{};
    int used{};
    int month = 1;

    cout << "How many buckwheat in total? (kg): ";
    while (!(cin >> buckwheat) || buckwheat <= 0) { // легкая проверка
        cout << "Incorrect input, dont use letters: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "How many you wanna used? (kg): ";
    while (!(cin >> used) || used <= 0) { // легкая проверка
        cout << "Incorrect input, dont use letters: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    if ((used > buckwheat) || (buckwheat % used != 0)) {
        cerr << "The total amount of buckwheat should be divided by the planned expenses without a remainder or be less than the expenses. Restart a programm and try again\n";
        return 1;
    }
    else {
        while (buckwheat > 0) {
            buckwheat -= used;
            month++;
            cout << "After " << month << " month " << buckwheat << " buckwheat's left\n";
        }
    }
    cout << "Buckwheat  will be completely gone in " << month - 1 << " months" << endl;
    return 0;
}