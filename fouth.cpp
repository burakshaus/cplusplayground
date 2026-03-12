#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(){
cout <<"Please enter a floating-point value:";
double n = 0;
cin >> n;
cout << "n == " << n << '\n';
for(int i = 1; i<4; i++){
n += 1;
cout << "n == " << n << '\n';
}
cout << "Square root of n ="<< sqrt(n) << '\n' ;
}
