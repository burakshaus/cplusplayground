#include <iostream>
#include <string>

int main() {
	std::string input;
std::getline(std::cin, input);

    for (char c : input) {
        std::cout << c << " " << static_cast<int>(c) << std::endl;
    }

    return 0;
}
