#include <iostream>
#include <vector>
#include <algorithm> // Required for sorting

int main() {
    std::vector<double> temps;
    double temp;

    std::cout << "Enter temperatures (any non-number to stop): ";
    
    // 1. Corrected input loop
    while (std::cin >> temp) {
        temps.push_back(temp);
    }

    // Handle empty input to avoid division by zero
    if (temps.empty()) {
        std::cout << "No data entered." << std::endl;
        return 0;
    }

    // 2. Initialize sum correctly
    double sum = 0;
    for (double x : temps) {
        sum += x;
    }

    std::cout << "Average temperature: " << sum / temps.size() << std::endl;

    // 3. Sorting (C++20 style)
    std::ranges::sort(temps);

    // 4. Median logic
    std::cout << "Median temperature: " << temps[temps.size() / 2] << std::endl;

    // g++ -std=c++20 temps.cpp -o temps.out
    return 0;
}
