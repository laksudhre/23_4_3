#include <iostream>
#include <map>

#define WAGONS_COUNT 10
#define OPTIMAL_PASSENGERS 20
#define CALL(func, param) { func(param); }

void userInput(std::map<int, int>& passengersCount) {
    for (int i = 0; i < WAGONS_COUNT; i++) {
        std::cout << "Enter the number of passengers on wagon " << (i + 1) << ": ";
        int passengers = 0;
        std::cin >> passengers;
        passengersCount[i + 1] = passengers;
    }
}

void show(const std::map<int, int>& passengers) {
    int lessOptimal = 0, moreOptimal = 0, passengersCount = 0;
    for (auto const& pair : passengers) {
        if (pair.second < OPTIMAL_PASSENGERS) {
            ++lessOptimal;
        }
        if (pair.second > OPTIMAL_PASSENGERS) {
            ++moreOptimal;
        }
        passengersCount += pair.second;
    }

    std::cout << "Wagons with less than optimal passenger count: " << lessOptimal << std::endl;
    std::cout << "Wagons with more than optimal passenger count: " << moreOptimal << std::endl;
    std::cout << "Total passengers count: " << passengersCount << std::endl;
}

int main() {
    std::map<int, int> passengers;
    CALL(userInput, passengers);
    CALL(show, passengers);
    return 0;
}
