#include <iostream>
using namespace std;

int main()
{
    int a = 0;
    int b = 0;
    cout << "Enter A: ";
    cin >> a;
    cout << "Enter B: ";
    cin >> b;
    cout << "\n";
    cout << "First meaning is A = " << a << " and B = " << b << "\n";
    cout << "\n";
    swap(a, b);
    cout << "\n";
    cout << "Changing values, new meaning is A = " << a << " and B = " << b << endl;
    return 0;
}