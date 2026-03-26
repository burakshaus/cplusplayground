#include <iostream>
#include <string>
using namespace std;
int main(){
cout << "Do you like fish?\n";
string s;
cin>>s;
int a = s;
switch(a){
case "no":
	cout <<"you're idiot\n";
	break;
case "yes":
	cout <<"yeeeees\n";
	break;
default:
	cout << "an exception occured.\n";
}
}
