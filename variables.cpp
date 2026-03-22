#include <iostream>
#include <string>
using namespace std;
int main (){
cout << "Please type two integer values followed by enter: " << '\n';
int val1 ,val2, difference;
cin >> val1 >> val2;
if(val1<val2){
cout << "first integer is the smallest" <<'\n';
cout << "second integer is the largest" <<'\n';
difference = val2-val1;
} else if(val2 < val1){
cout << "second integer is the smallest" <<'\n';
cout << "first integer is the largest" << '\n';
difference = val1-val2;
} else {
cout << "Both are equal" <<'\n';
difference = 0;
}

int sum = val1+val2;
int product = val1*val2;
double ratio = (double) val1/ (double)val2 * 100;
cout << "Sum of these : " << sum << "difference of these : " << difference <<"product of these two: " << product << "ratio of these two :" << ratio<<'\n'; 
}
