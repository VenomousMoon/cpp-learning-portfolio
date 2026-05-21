#include <iostream>
#include <string>
#include <cctype>
using namespace std;

static bool isCorrectName(const string& str) { // функция корректности имени
    if (str.empty()) return false;
    for (char ch : str) {
        if (!isalpha(ch) && ch != ' ') {
            return false;
        }
    }
    return true;
}
static bool isCorrectDebt(const string& str) { // функция корректности общей суммы
    if (str.empty()) return false;
    for (char ch : str) {
        if (!isdigit(ch) && ch != ' ') {
            return false;
        }
    }
    return true;
}
static bool isCorrectSum(const string& str) { // функция корректности вносимой суммы
    if (str.empty()) return false;
    for (char ch : str) {
        if (!isdigit(ch) && ch != ' ') {
            return false;
        }
    }
    return true;
}

int main()
{
    string debtS{}; // общая сумма
    string sumS{}; // вносимая сумма
    string name{}; // имя
    cout << "Enter name: ";
    while (true) {
        getline(cin, name);
        if (isCorrectName(name)) {
            break;
        }
        cerr << "Only letters allowed. Try input again. Enter name: ";
    }
    cout << "Enter sum of debt: ";
    while (true) {
        getline(cin, debtS);
        if (isCorrectDebt(debtS)) {
            break;
        }
        cerr << "Only numbers allowed. Try input again. Enter sum of debt: ";
    }
    cout << "Enter the amount you want to deposit: ";
    while (true) {
        getline(cin, sumS);
        if (isCorrectSum(sumS)) {
            break;
        }
        cerr << "Only numbers allowed. Try input again. Enter the amount you want to deposit: ";
    }
    int debt = stoi(debtS);
    int sum = stoi(sumS);
    while (true) {
        if (debt < sum) {
            cout << "Your change: " << sum - debt << "\n";
            break;
        }
        else if (debt == sum) {
            cout << "Debt is fully paid!\n";
            break;
        }
        else { // debt > sum
            debt -= sum;
            cout << "Remaining debt: " << debt << "\n";

            // Спрашиваем следующий платёж
            cout << "Enter next payment: ";
            while (true) {
                getline(cin, sumS);
                if (isCorrectSum(sumS)) {
                    sum = stoi(sumS);
                    break;
                }
                cerr << "Only numbers allowed. Try again: ";
            }
        }
    }
    return 0;
}
