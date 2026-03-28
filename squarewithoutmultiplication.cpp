#include <iostream>

void calculateSquare(int x) {
    int result = 0; // 1. Renamed to avoid conflict and 2. Initialized to 0
    
    for(int i = 0; i < x; ++i) {
        result += x;
    }
    
    std::cout << "The square of " << x << " is: " << result << std::endl;
}

int main() {
    calculateSquare(4);
    return 0;
}
