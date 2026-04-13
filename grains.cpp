#include <iostream>

int main() {
    long long grains_on_square = 1;
    long long total_grains = 0;
    int square = 0;

    // These are the three targets you asked for
    long long target1 = 100;
    long long target2 = 100000;
    long long target3 = 10000000;

    // Booleans to make sure we only print the result once per target
    bool hit1 = false, hit2 = false, hit3 = false;

    std::cout << "Calculating squares needed...\n" << std::endl;

    while (square < 64) {
        square++;
        total_grains += grains_on_square;

        // Check if we passed the 100 mark
        if (!hit1 && total_grains >= target1) {
            std::cout << "For " << target1 << " grains, we need " << square << " squares." << std::endl;
            hit1 = true;
        }

        // Check if we passed the 100,000 mark
        if (!hit2 && total_grains >= target2) {
            std::cout << "For " << target2 << " grains, we need " << square << " squares." << std::endl;
            hit2 = true;
        }

        // Check if we passed the 10,000,000 mark
        if (!hit3 && total_grains >= target3) {
            std::cout << "For " << target3 << " grains, we need " << square << " squares." << std::endl;
            hit3 = true;
            break; // We can stop early since we hit your highest target
        }

        grains_on_square *= 2; // Double the rice for the next square
    }

    return 0;
}
