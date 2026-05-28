#include <iostream>
using namespace std;

int main () {
    cout << "Squares of 1 to 9 \n";
    
    for(int i = 1; i < 10; i++) {
        cout << i << "\t ";
        cout << i * i << "\n";
    }
    
    return 0;
}
