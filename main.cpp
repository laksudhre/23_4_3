#include <iostream>
#include <map>

#define WAGONS_COUNT 10
#define OPTIMAL_PASSENGERS 20
#define CALL1(func, param) for (int i = 0; i < WAGONS_COUNT; ++i) { func(param, i); }
#define CALL2(func, param1, param2, param3, param4) for (int i = 0; i < WAGONS_COUNT; ++i) { func(param2, param3, param4, param1[i]); }

void userInput(std::map<int, int>& passengers, const int& key) {
    std::cout << "Enter passengers count for wagon " << key + 1 << ": ";
    std::cin >> passengers[key];
}

void checkPassengers(int& total, int& less, int& more, const int& value) {
    if (value < OPTIMAL_PASSENGERS) {
        ++less;
    } else if (value > OPTIMAL_PASSENGERS) {
        ++more;
    }
    total += value;
}

int main() {
    std::map<int, int> passengers;
    int totalPassengers = 0;
    int lessPassengers = 0;
    int morePassengers = 0;
    CALL1(userInput, passengers);
    CALL2(checkPassengers, passengers, totalPassengers, lessPassengers, morePassengers);
    std::cout << "Total passengers: " << totalPassengers << std::endl;
    std::cout << "Less passengers than optimal: " << lessPassengers << std::endl;
    std::cout << "More passengers than optimal: " << morePassengers << std::endl;
    return 0;
}
