#include <iostream>
#include <string>
#include <cctype>

static bool isValid(const std::string& str) {
    if (str.empty()) return false;
    if (str[0] == ' ') return false;
    for (char c : str) {
        if (!isalpha(c) && c != ' ' && !ispunct(c)) {
            return false;
        }
    }
    return true;
}

static int wordsCount(const std::string& str) {
    int words{};
    bool wasSpace = true;

    for (char c : str) {
        if (c == ' ') {
            wasSpace = true;
        }
        else {
            if (wasSpace) {
                ++words;
                wasSpace = false;
            }
        }
    }
    return words;
}

int main()
{
    std::string sentence{};

    std::cout << "Enter any sentence: ";
    while (true) {
        std::getline(std::cin, sentence);
        if (isValid(sentence)) {
            break;
        }
        std::cout << "Enter any sentence again but without the numbers and space first: ";
    }
    
    int words = wordsCount(sentence);

    if (words == 1) {
        std::cout << "There is 1 word\n";
    }
    else if (words == 0) {
        std::cout << "No one word here\n";
    }
    else {
        std::cout << "There are " << words << " words\n";
    }
    return 0;
}