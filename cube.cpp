#include <iostream>
using namespace std;

int main() {
    cout << "Cube of 1 to 9\n";
    
    // Changed i=0 to i=1 to match your text "1 to 9"
    for(int i = 1; i < 10; i++) {
        cout << i << "\t"; // Fixed: added the missing second '<'
        cout << i * i * i << "\n";
    }
    
    return 0;
}
