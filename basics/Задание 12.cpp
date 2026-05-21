#include <iostream>
using namespace std;

int main()
{ 
    int speed{};
    int high{};
    cout << "Enter the speed: ";
    while (!(cin >> speed) || speed < 750 || speed > 850) {
        cerr << "Enter speed between 750 and 850\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    cout << "Enter the high: ";
    while (!(cin >> high) || high < 9000 || high > 9500) {
        cerr << "Enter high between 9000 and 9500\n";
        cin.clear();
        cin.ignore(1000000, '\n');
    }
    cout << "Data correct" << endl;
    return 0;
}
