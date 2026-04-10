#include <iostream>
#include <vector>

int main() {
    std::vector<int> myvector;
    int input;

    std::cout << "Please type integers (press Ctrl+D or type a letter to stop): " << std::endl;

    // Use 'while' for conditions that depend on input success
    while (std::cin >> input) {
        myvector.push_back(input);
    }

    std::cout << "\nYour vector contains: ";
    
    // This 'range-based for loop' you wrote is perfect!
    for (int i : myvector) {
        std::cout << i << ", ";
    }

    std::cout << std::endl;
    return 0;
}
