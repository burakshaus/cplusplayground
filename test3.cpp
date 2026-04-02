#include <iostream>
#include <string>

int main() {
    std::string input;
    
    std::cout << "Enter a string: ";
    // Use getline to include spaces, or cin >> input for a single word
    std::getline(std::cin, input);

    for (char c : input) {
        // Casting 'c' to (int) reveals its underlying numeric value
        std::cout << c << " " << static_cast<int>(c) << std::endl;
    }

    return 0;
}
