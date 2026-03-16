#include <iostream>
#include <string>
using namespace std;
int main(){
string first_name,second_name,last_name;
int age;
cout << "Please type your full name and your age(followed by ente at each time):"<< '\n';
cin >> first_name >> second_name >> last_name >> age;
string outstring = first_name + " " + second_name + " " + last_name ; 
cout << outstring << " " << age <<'\n';
}
