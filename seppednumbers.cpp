#include <iostream>
#include <string>

int main() {
    std::string input;

    std::cout << "Please enter a spelled-out number (e.g., 'zero', 'two'): ";
    
    // Using while(true) so you can test multiple inputs easily
    while (std::cin >> input) {
        if (input == "zero") {
            std::cout << 0 << "\n";
        } 
        else if (input == "one") {
            std::cout << 1 << "\n";
        } 
        else if (input == "two") {
            std::cout << 2 << "\n";
        } 
        else if (input == "three") {
            std::cout << 3 << "\n";
        } 
        else if (input == "four") {
            std::cout << 4 << "\n";
        } 
        else {
            std::cout << "not a number I know\n";
        }
        
        std::cout << "\nEnter another or press Ctrl+C to exit: ";
    }

    return 0;
}
