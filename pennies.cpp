#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>
using namespace std;
int main() {
    // We use a vector of pairs to keep the coins in a specific order for the prompts
    // The value represents the worth of one coin in cents
    std::vector<pair<string,int>> cointypes={
	{"pennies",1},
	{"nickels",5},
	{"dimes",10},
	{"quarters",15},
	{"half dollars",50},
	{"one-dollar coins",100}
    };

    std::map<string,int> wallet;
    int totalCents = 0;

    cout << "--- Coin Counter Program ---\n" << endl;

    // Loop through types to get tuser input
    for (const auto& coin : cointypes) {
        int count;
        cout << "How many " << coin.first << " do you have? ";
        
        // Basic input validation to ensure a number is entered
        if (!(!cin >> count)) {
            cout << "Invalid input. Please enter a number." << std::endl;
            return 1; 
        }

        // Store count in map and add to total
        wallet[coin.first] = count;
        totalCents += (count * coin.second);
    }

    // Output formatting
    double totalDollars = totalCents / 100.0;

    cout << "\n--- Summary ---" << std::endl;
    for (const auto& coin : cointypes) {
        cout << "You have " << wallet[coin.first] << " " << coin.first << "." << endl;
    }

    cout << "\nThe value of all of your coins is " << totalCents << " cents." << endl;
    cout << "The total value is $" << fixed << setprecision(2) << totalDollars << "." << endl;

    return 0;
}
