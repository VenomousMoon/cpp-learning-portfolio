#include <iostream>
#include <string>
#include <cwctype>
#include <clocale>
#include <fcntl.h>
#include <io.h>

static bool isValid(const std::wstring& str) {
    if (str.empty()) return false;
    if (str[0] == ' ') return false;
    for (wchar_t c : str) {
        if (!iswalpha(c) && c != ' ' && !iswpunct(c)) {
            return false;
        }
    }
    return true;
}

static int wordsCount(const std::wstring& str) {
    int words{};
    bool wasSpace = true;

    for (wchar_t c : str) {
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
    setlocale(LC_ALL, "Russian");
    (void)_setmode(_fileno(stdout), _O_U16TEXT);
    (void)_setmode(_fileno(stdin), _O_U16TEXT);
    
    std::wstring sentence{};

    std::wcout << L"Введите любое предложение (ru/eng): ";
    while (true) {
        std::getline(std::wcin, sentence);
        if (isValid(sentence)) {
            break;
        }
        std::wcout << L"Введите еще раз, но без цифр и пробела вначале: ";
    }

    int words = wordsCount(sentence);

    if (words == 1) {
        std::wcout << L"Тут одно слово\n";
    }
    else if (words == 0) {
        std::wcout << L"Тут нет слов\n";
    }
    else {
        std::wcout << L"Тут " << words << L" слова\n";
    }
    return 0;
}