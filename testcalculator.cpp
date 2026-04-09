#include <iostream>
#include <string>

using namespace std;

int main() {
    double first, second, result;
    string op = ""; // Renamed from 'operator'

    cout << "Please type a number: ";
    cin >> first;

    cout << "Please type operator (+, -, *, /): ";
    cin >> op;

    cout << "Please now type second number: ";
    cin >> second; // Added this missing line

    if (op == "+") {
        result = first + second; // Fixed 'firat' typo
    } else if (op == "-") {
        result = first - second;
    } else if (op == "*") {
        result = first * second;
    } else if (op == "/") {
        // Basic check for division by zero
        if (second != 0) {
            result = first / second;
        } else {
            cout << "Error: Division by zero!" << endl;
            return 1;
        }
    } else {
        cout << "Invalid operator!" << endl;
        result = -1;
    }

    cout << "result: " << result << endl;
    
    return 0;
}
