#include <iostream>
#include <string>
using namespace std;
int main () {
cout << "type 1 for km type 2 for mile" << '\n';
int choise ;
cin >>choise ;
if(choise == 1){
int km ;
cout << "please enter how many kilometer: " << '\n';
cin >> km;
double miles = km /1609;
cout << miles << " miles" << '\n';
} else if(choise == 2){
int miles ;
cout << "Please enter how many miles "<< '\n';
cin >> miles ;
double km = miles/1609;
cout << km << " kilometers" << '\n';
} else {
cout << "An error occured" << '\n';
}

}
