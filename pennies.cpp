#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>

int main() {
    // We use a vector of pairs to keep the coins in a specific order for the prompts
    // The value represents the worth of one coin in cents
    std::vector<std::pair<std::string, int>> coinTypes = {
        {"pennies", 1},
        {"nickels", 5},
        {"dimes", 10},
        {"quarters", 25},
        {"half dollars", 50},
        {"one-dollar coins", 100}
    };

    std::map<std::string, int> wallet;
    int totalCents = 0;

    std::cout << "--- Coin Counter Program ---\n" << std::endl;

    // Loop through types to get user input
    for (const auto& coin : coinTypes) {
        int count;
        std::cout << "How many " << coin.first << " do you have? ";
        
        // Basic input validation to ensure a number is entered
        if (!(std::cin >> count)) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            return 1; 
        }

        // Store count in map and add to total
        wallet[coin.first] = count;
        totalCents += (count * coin.second);
    }

    // Output formatting
    double totalDollars = totalCents / 100.0;

    std::cout << "\n--- Summary ---" << std::endl;
    for (const auto& coin : coinTypes) {
        std::cout << "You have " << wallet[coin.first] << " " << coin.first << "." << std::endl;
    }

    std::cout << "\nThe value of all of your coins is " << totalCents << " cents." << std::endl;
    std::cout << "The total value is $" << std::fixed << std::setprecision(2) << totalDollars << "." << std::endl;

    return 0;
}
