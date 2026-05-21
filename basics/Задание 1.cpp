#include <iostream> 
int main() {
    int lap = 4;
    int engine = 254;
    int wheels = 93;
    int handlebar = 49;
    int wind = 21;
    int rain = 17;
    int speed = engine + wheels + handlebar - wind - rain;
    std::cout << "===================\n";
    std::cout <<  "Super race. Lap: " << lap << "\n";
    std::cout << "===================\n";
    std::cout << "Schumacher (" << speed << ")\n";
    std::cout << "===================\n";
    std::cout << "Driver: Schumacher\n";
    std::cout << "Speed: " << speed << "\n";
    std::cout << "-------------------\n";
    std::cout << "Equipment\n";
    std::cout << "Engine: +" << engine << "\n";
    std::cout << "Wheels: +" << wheels << "\n";
    std::cout << "Handlebar: +" << handlebar << "\n";
    std::cout << "-------------------\n";
    std::cout << "Actions of bad weather\n";
    std::cout << "Wind: -" << wind << "\n";
    std::cout << "Rain: -" << rain << "\n";
    return 0;
}