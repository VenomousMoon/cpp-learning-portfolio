#include <iostream>
using namespace std;

int main()
{
    int num{};
    cout << "Enter any positive number: ";
    while (!(cin >> num) || num <= 0) {
        cerr << "Incorrect input. Enter any positive number\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    int count{};
    while (num != 0) {
        num /= 10;
        count++;
    }
    cout << "Here is " << count << " digits" << endl;
    return 0;
}