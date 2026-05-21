#include <iostream>
#include <string>
#include <cctype>

static bool isValid(const std::string& str) {
    if (str.empty()) return false;
    for (char c : str) {
        if (!isalpha(c) && c != ' ' && !ispunct(c)) {
            return false;
        }
    }
    return true;
}

static int countOfSpaces(const std::string& str) {
    int count{};
    for (char c : str) {
        if (c == ' ') {
            ++count;
        }
    }
    return count;
}

int main()
{
    std::string sentence{};
    
    std::cout << "Enter any sentense: ";

    while (true) {
        std::getline(std::cin, sentence);
        if (isValid(sentence)) {
            break;
        }
        std::cout << "!!!Enter without numbers!!!\n";
        std::cout << "Enter any sentence: ";
    }

    int spaces = countOfSpaces(sentence);

    if (spaces == 1) {
        std::cout << "Is " << spaces << " space here\n";
    }
    else if (spaces == 0) {
        std::cout << "It sentence without the spaces\n";
    }
    else {
        std::cout << "Are " << spaces << " spaces here\n";
    }
    return 0;
}