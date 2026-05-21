#include <iostream>
#include <cctype>
#include <string>
#include <cmath>
using namespace std;

static bool isCorrectMeaning(const string& str) { // проверка корректности
	if (str.empty()) return false;
	for (char c : str) {
		if (!isdigit(c)) {
			return false;
		}
	}
	return true;
}

int main()
{
	string sumS{}; // сумма
	string sumAfterYearsS{}; //желаемая сумма
	string percentageS{}; // процентная ставка

	cout << "Enter sum which you wanna deposit: "; // проверка ввода суммы
	while (true) {
		cin >> sumS;
		if (isCorrectMeaning(sumS)) {
			break;
		}
		cerr << "Please enter positive sum or dont use letters\n";
	}

	cout << "Enter the deposit percentage: "; // проверка ввода процентной ставки
	while (true) {
		cin >> percentageS;
		if (isCorrectMeaning(percentageS)) {
			break;
		}
		cerr << "Please enter positive percentage or dont use letters\n";
	}

	cout << "Enter the sum which you wanna recived: "; // проверка ввода желаемой суммы
	while (true) {
		cin >> sumAfterYearsS;
		if (isCorrectMeaning(sumAfterYearsS)) {
			break;
		}
		cerr << "Please enter positive sum or dont use letters\n";
	}

	double sum = stod(sumS); // преобразование строк в числа
	double recivedSum = stod(sumAfterYearsS);
	double percent = stod(percentageS);
	int years = 0; // счетчик лет

	while (sum < recivedSum) { // пока сумма меньше желаемой суммы
		sum += sum * (percent / 100);
		sum = floor(sum);
		years++;
	}
	cout << "You need to save for " << years << " years" << endl;
	return 0;
}
