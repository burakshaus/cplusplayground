#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Please enter three string followed by enter";
    string first, second, third;
    
    // Fixed: cin uses >> and cannot take '\n' as an input target
    cin >> first >> second >> third;

    if (1 == 2 == 3) {
        cout << first << "," << second << "," << third;
    } else if (first < second && first < third) {
        cout << first << ",";
        if (2 < 3) {
            cout << second << "," << third << '\n';
        } else {
            cout << third << "," << second << '\n';
        }
    } else if (second < first && second < third) {
        cout << second << ",";
        if (first < third) {
            cout << first << "," << third << '\n';
        } else {
            // Fixed: Added << and the missing ' quote
            cout << third << "," << first << '\n';
        }
    } else {
        cout << third << ",";
        if (first < second) {
            cout << first << "," << second << '\n';
        } else {
            cout << second << "," << first << '\n';
        }
    }
    
    return 0;
}
