#include <iostream>
#include <string>
#include <cwctype>
#include <clocale>
#include <fcntl.h>
#include <io.h>

static bool isValidLetters(const std::wstring& str) {
    if (str.empty()) return false;
    for (wchar_t c : str) {
        if (!iswalpha(c)) {
            return false;
        }
    }
    return true;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    (void)_setmode(_fileno(stdout), _O_U16TEXT);
    (void)_setmode(_fileno(stdin), _O_U16TEXT);

    std::wstring name{};
    std::wstring surname{};

    std::wcout << L"Введите свое имя: ";
    while (true) {
        std::getline(std::wcin, name);
        if (isValidLetters(name)) {
            break;
        }
        std::wcout << L"Неверное имя, повторите еще раз: ";
    }

    std::wcout << L"Введите свою фамилию: ";
    while (true) {
        std::getline(std::wcin, surname);
        if (isValidLetters(surname)) {
            break;
        }
        std::wcout << L"Неверная фамилия, повторите еще раз: ";
    }

    std::wcout << L"Вы ввели все верно!\n";
    return 0;
}