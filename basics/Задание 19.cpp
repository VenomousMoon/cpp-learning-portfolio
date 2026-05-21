#include <iostream>
#include <cctype>
#include <string>

using namespace std;

static bool isValidMeaning(const string& str) {
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
    string fileSize{};
    string connectionSpeed{};

    cout << "Enter file size (mb): ";
    while (true) {
        cin >> fileSize;
        if (isValidMeaning(fileSize)) {
            break;
        }
        cout << "File size must not be less than zero and must contain letters\n";
        cout << "Try again (mb): ";
    }

    cout << "Enter connection speed (mb/s): ";
    while (true) {
        cin >> connectionSpeed;
        if (isValidMeaning(connectionSpeed)) {
            break;
        }
        cout << "Connectoin speed must not be less than zero and must contain letters\n";
        cout << "Try again (mb/s): ";
    }

    int size = stoi(fileSize);
    int speed = stoi(connectionSpeed);
    int downloaded{};

    for (int seconds = 1; downloaded < size; seconds++) {
        int willDownload = speed;
        if (downloaded + willDownload > size) {
            willDownload = size - downloaded;
        }
        downloaded += willDownload;

        int percent = (downloaded * 100) / size;
        cout << "Seconds have passed: " << seconds << ". Downloaded on " << percent << "%" << "\n";
    }
    return 0;
}