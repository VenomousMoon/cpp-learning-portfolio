#include <iostream>
#include <string>
#include <cctype>
using namespace std;

static bool isCorrectCommand(const string& str) {
    if (str.empty() || str.length() != 1) return false;
    for (char c : str) {
        char lower = tolower(c);
        if (!isalpha(c) || (lower != 'w' && lower != 'a' && lower != 's' && lower != 'd')) {
            return false;
        }
    }
    return true;
}


int main()
{
    const int WIDTH = 16;
    const int HEIGHT = 20;

    int x = WIDTH / 2;
    int y = HEIGHT / 2;

    cout << "The rover is at position (" << x << ";" << y << ")" << "\n";

    while (true) {
        string command{};
        cout << "Enter comand (w,a,s,d): ";

        while (true) {
            cin >> command;
            if (isCorrectCommand(command)) {
                break;
            }
            cout << "Enter the one allowed letters only or dont trying enter digit: ";
        }

        if (command == "w") {
            if (y < HEIGHT) {
                y++;
            }
            else if (y == HEIGHT) {
                cout << "The rover reached its maximum Y - axis coordinate\n";
            }
        }

        if (command == "s") {
            if (y > 0) {
                y--;
            }
            else if (y == 0) {
                cout << "The rover reached its minimum Y - axis coordinate\n";
            }
        }

        if (command == "a") {
            if (x > 0) {
                x--;
            }
            else if (x == 0) {
                cout << "The rover reached its minimum X - axis coordinate\n";
            }
        }

        if (command == "d") {
            if (x < WIDTH) {
                x++;
            }
            else if (x == WIDTH) {
                cout << "The rover reached its maximum X - axis coordinate\n";
            }
        }
        cout << "New position is (" << x << ":" << y << ")" << "\n";
    }
    return 0;
}
    
