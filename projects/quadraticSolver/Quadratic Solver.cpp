#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

static int parsedNumber(const std::string& num) {
    if (num.empty()) return 0;
    
    int result{};
    int start{};
    bool negative = false;

    if (num[0] == '-') {
        negative = true;
        start = 1;
    }
    if (num[0] == '+') {
        start = 1;
    }
    for (int i = start; i < num.length(); ++i) {
        result = result * 10 + (num[i] - '0');
    }
    return negative ? -result : result;
}

static int parsedA(const std::string& str, size_t x2pos) {
    std::string aPos = str.substr(0, x2pos);
    if (aPos.empty() || aPos == "+") return 1;
    if (aPos == "-") return -1;
    return parsedNumber(aPos);
}

static int parsedB(const std::string& str, size_t x2pos, size_t xpos) {
    std::string bPos = str.substr(x2pos + 3, xpos - (x2pos + 3));
    if (bPos.empty() || bPos == "+") return 1;
    if (bPos == "-") return -1;
    return parsedNumber(bPos);
}

static int parsedC(const std::string& str, size_t xpos, size_t equalPos) {
    std::string cPos = str.substr(xpos + 1, equalPos - (xpos + 1));
    if (cPos.empty()) return 0;
    return parsedNumber(cPos);
}

static void getRoots(int a, int b, int c) {
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        double x2 = (-b - sqrt(discriminant)) / (2 * a);
        std::cout << "X1: " << x1 << "\n";
        std::cout << "X2: " << x2 << "\n";
    }
    else if (discriminant == 0) {
        double x = -b / (static_cast<double>(2) * a);
        std::cout << "X: " << x << "\n";
    }
    else {
        std::cout << "No real roots\n";
    }
}

static bool parseEquation(std::string& equation, size_t& equalSign, size_t& x2pos, size_t& xpos) {
    while (true) {
        std::cout << "Enter the equation: ";
        std::getline(std::cin, equation);

        equation.erase(std::remove(equation.begin(), equation.end(), ' '), equation.end());

        equalSign = equation.find('=');
        if (equalSign == std::string::npos) {
            std::cout << "Sign '=' not found. Try again.\n";
            continue;
        }

        std::string rightPart = equation.substr(equalSign + 1);
        if (rightPart != "0") {
            std::cout << "After '=' must be 0. Try again.\n";
            continue;
        }

        x2pos = equation.find("x^2");
        if (x2pos == std::string::npos) {
            std::cout << "x^2 not found. Not a quadratic equation.\n";
            continue;
        }

        xpos = equation.find('x', x2pos + 3);
        if (xpos == std::string::npos) {
            std::cout << "Linear term 'x' not found.\n";
            continue;
        }
        return true;
    }
}
int main()
{
    std::string equation{};
    size_t x2pos{}, xpos{}, equalSign{};

    parseEquation(equation, equalSign, x2pos, xpos);
       
    int a = parsedA(equation, x2pos);
    int b = parsedB(equation, x2pos, xpos);
    int c = parsedC(equation, xpos, equalSign);

    getRoots(a, b, c);

    return 0;
}