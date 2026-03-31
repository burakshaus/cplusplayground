#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

int main() {
    std::vector<double> values_in_meters;
    
    double input;
    std::string unit;
    
    std::cout << "Enter values with units (cm, m, in, ft). Example: 10cm or 2 m." << std::endl;
    std::cout << "Type '|' or 'exit' to finish." << std::endl;

    while (std::cin >> input >> unit) {
        double converted_value = 0;
        bool valid_unit = true;

        // Conversion Logic to Meters
        if (unit == "m") {
            converted_value = input;
        } else if (unit == "cm") {
            converted_value = input / 100.0;
        } else if (unit == "in") {
            converted_value = input * 0.0254;} else if (unit == "ft") {
            converted_value = input * 0.3048; 
        } else {
            std::cout << "Unknown unit: " << unit << ". Value ignored." << std::endl;
            valid_unit = false;
        }

        if (valid_unit) {
            values_in_meters.push_back(converted_value);
            std::cout << "Saved: " << converted_value << "m" << std::endl;
        }
    }

    if (!values_in_meters.empty()) {
        std::ranges::sort(values_in_meters);

        std::cout << "\n--- Sorted Values (in Meters) ---" << std::endl;
        for (double val : values_in_meters) {
            std::cout << val << " m" << std::endl;
        }
    } else {
        std::cout << "No valid values were entered." << std::endl;
    }

    return 0;
}
