#include <iostream>
#include <map>
#include <ranges>

#define WAGONS_COUNT 10
#define OPTIMAL_PASSENGERS 20
#define CALL(func, param) { func(param); }
#define FOR(i, n) for (int i = 0; i < n; i++)
#define FOR_AUTO(it, param) for (auto& it : std::views::values(param))

void userInput(std::map<int, int>& passengersCount) {
    FOR(i, WAGONS_COUNT) {
        std::cout << "Enter the number of passengers on wagon " << (i + 1) << ": ";
        int passengers = 0;
        std::cin >> passengers;
        passengersCount[i + 1] = passengers;
    }
}

void show(const std::map<int, int>& passengers) {
    int lessOptimal = 0, moreOptimal = 0, passengersCount = 0;
    FOR_AUTO(it, passengers) {
        if (it < OPTIMAL_PASSENGERS) {
            ++lessOptimal;
        }
        if (it > OPTIMAL_PASSENGERS) {
            ++moreOptimal;
        }
        passengersCount += it;
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
