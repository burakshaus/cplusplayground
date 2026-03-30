#include <iostream>
#include <vector>
#include <string>    
#include <algorithm> 
int main() {
    // 1. Use std::string
    std::vector<std::string> words;

    std::cout<<"Type crtl+z or crtl+d to quit"<<std::endl;
    // 2. Use std::string here too
    for (std::string temp; std::cin >> temp; ) {
        words.push_back(temp);
    }

    std::cout << "Number of words: " << words.size() << std::endl;

    // 3. Sort the range
    std::ranges::sort(words);

    // 4. Use size_t for indices and fixed the if-statement typo
    for (size_t i = 0; i < words.size(); ++i) {
        // Removed the extra ';' after i==0
        if (i == 0 || words[i - 1] != words[i]) {
            std::cout << words[i] << std::endl;
        }
    }

    return 0;
}
