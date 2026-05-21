#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int employers{}; // задание расчитано на 3 рабочих
    int salary{}; // но тут ручной ввод количества сотрудников
    int totalSalary{}; // для подсчетов 
    int max = INT_MIN; // максимальная зарплата
    int min = INT_MAX; // минимальная зарплата

    cout << "How many employers here: ";
    while (!(cin >> employers)) {
        cout << "Enter the number of employees\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    cout << "\n";

    for (int count{}; count < employers; count++) {
        cout << "How much you paying for " << count << " employer: ";
        while (!(cin >> salary) || salary < 0) {
            cerr << "Incorrect meaning, tre again but not negative\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        totalSalary += salary;
        if (salary > max) {
            max = salary;
        }
        if (salary < min) {
            min = salary;
        }
    }
    cout << "\n";

    cout << "Total amount which you paying: " << totalSalary << char(36) << "\n";
    cout << "Average salary by department: " << totalSalary / employers << char(36) << "\n";
    cout << "Max salary in department: " << max << char(36) << "\n";
    cout << "Min salary in department: " << min << char(36) << "\n";
    return 0;
}