#include <iostream>
using namespace std;

int main() {
    cout << "4 power of 1 to 9\n"; 
    
    for(int i = 1; i < 10; i++) {
        cout << i << "\t";
        cout << i * i * i * i << "\n"; 
    }
    
    return 0;
}
