#include <iostream>

using namespace std;

int main() {
    char str[20]; 
    
    cout << "Enter your name: " << std::endl;
    cin.getline(str, 20); 
    cout << "Your name is: " << str << std::endl; 
    return 0;
}
