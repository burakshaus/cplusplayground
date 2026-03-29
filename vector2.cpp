#include <iostream>
#include <vector>

int main() {
    std::vector<int> myVector;

    std::cout << "Enter numbers (press Ctrl+D or enter a letter to stop): " << std::endl;

    // Corrected the double 'for' and syntax
    for (int temp; std::cin >> temp; ) {
        myVector.push_back(temp);
    }

    std::cout << "\nYou entered: " << std::endl;
    for (int i : myVector) {
        std::cout << i << " "; // Completed the std::cout
    }
    std::cout << std::endl;

    return 0;
}
