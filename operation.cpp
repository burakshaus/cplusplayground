#include <iostream>
#include <string>

int main() {
    std::string operation;
    double val1, val2;

    std::cout << "Enter an operation (+, -, *, /, plus, minus, mul, div) followed by two numbers: \n";

    // Read input in the order: string, double, double
    while (std::cin >> operation >> val1 >> val2) {
        double result = 0;
        bool valid = true;

        if (operation == "+" || operation == "plus") {
            result = val1 + val2;
        } 
        else if (operation == "-" || operation == "minus") {
            result = val1 - val2;
        } 
        else if (operation == "*" || operation == "mul") {
            result = val1 * val2;
        } 
        else if (operation == "/" || operation == "div") {
            if (val2 != 0) {
                result = val1 / val2;
            } else {
                std::cout << "Error: Division by zero is not allowed.\n";
                valid = false;
            }
        } 
        else {
            std::cout << "I don't know the operation: " << operation << "\n";
            valid = false;
        }

        if (valid) {
            std::cout << "The result of " << val1 << " " << operation << " " << val2 << " is " << result << "\n";
        }

        std::cout << "\nEnter another (or Ctrl+C to exit): ";
    }

    return 0;
}
