#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int price = 0;
    int all_passengers = 0;
    int total_passengers = 0;
    int passengers_enter = 0;
    int passenger_leaves = 0;
    double total_income = 0;

    string first_stop = "Seattle";
    string second_stop = "Portland";
    string third_stop = "Sacramento";
    string fourth_stop = "Los Angeles";

    cout << "Enter price of one trip: ";
    cin >> price;
    cout << "How many passengers now: ";
    cin >> all_passengers;
    cout << "\n";
    cout << "We are going, the trip cost is " << price << char(36) << "\n";
    cout << "\n";
    total_passengers = all_passengers;

    cout << "We arrive at the first stop: " << first_stop << "\n";
    cout << "How many passengers enter: ";
    cin >> passengers_enter;
    cout << "How many passengers leaves: ";
    cin >> passenger_leaves;
    all_passengers += (passengers_enter - passenger_leaves);
    total_passengers += passengers_enter;
    cout << "Currently, there are " << all_passengers << " passengers in the bus" << "\n";
    cout << "\n";
   
    cout << "We arrive at the second stop: " << second_stop << "\n";
    cout << "How many passengers enter: ";
    cin >> passengers_enter;
    cout << "How many passengers leaves: ";
    cin >> passenger_leaves;
    all_passengers += (passengers_enter - passenger_leaves);
    total_passengers += passengers_enter;
    cout << "Currently, there are " << all_passengers << " passengers in the bus" << "\n";
    cout << "\n";
   
    cout << "We arrive at the first stop: " << third_stop << "\n";
    cout << "How many passengers enter: ";
    cin >> passengers_enter;
    cout << "How many passengers leaves: ";
    cin >> passenger_leaves;
    all_passengers += (passengers_enter - passenger_leaves);
    total_passengers += passengers_enter;
    cout << "Currently, there are " << all_passengers << " passengers in the bus" << "\n";
    cout << "\n";
  
    cout << "We arrive at the first stop: " << fourth_stop << "\n";
    cout << "How many passengers enter: ";
    cin >> passengers_enter;
    cout << "How many passengers leaves: ";
    cin >> passenger_leaves;
    all_passengers += (passengers_enter - passenger_leaves);
    total_passengers += passengers_enter;
    cout << "\n";
  
    total_income = total_passengers * price;
    double rent = total_income / 4;
    double salary = total_income / 5;
    double fuel = total_income / 5;
    double tax = total_income * 0.166;
    double clear_income = total_income - (rent + salary + fuel + tax);
    cout << fixed << setprecision(2);
    cout << "Total income: " << total_income << char(36) << "\n";
    cout << "Clear income : " << clear_income << char(36) << endl;
    return 0;
}