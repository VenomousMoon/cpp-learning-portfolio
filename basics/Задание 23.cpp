#include <iostream>
#include <string>
#include <cctype>

static bool isValidNumber(const std::string& str) {
    if (str.empty()) return false;
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

static std::string getValidNumber(const std::string& number) {
    std::string num{};
    while (true) {
        std::cout << number;
        std::cin >> num;
        if (isValidNumber(num)) return num;
        std::cout << "Enter positive number only, without letters\n";
    }
}

static int parsePositive(const std::string& number) {
    int result{};
    for (char c : number) {
        result = result * 10 + (c - '0');
    }
    return result;
}

static int max(const int a, const int b, const int c) {
    return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
}

int main()
{
    std::string firstNum = getValidNumber("Enter any positive number: ");
    std::string secondNum = getValidNumber("Enter any positive number: ");
    std::string thirdNum = getValidNumber("Enter any positive number: ");

    int a = parsePositive(firstNum);
    int b = parsePositive(secondNum);
    int c = parsePositive(thirdNum);

    if (a == b && a == c) {
        std::cout << "Numbers are equal\n";
    }
    else {
        std::cout << "The largest number is: " << max(a, b, c) << "\n";
    }
    return 0;
}