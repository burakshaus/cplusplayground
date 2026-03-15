#include <iostream>
#include <string>
using namespace  std;
int main(){
cout <<"Hello you fucking cunt first type your name and lastname"<< '\n';
string name, lastname;
int age = -1;
cin >> name;
if(name.length() == 0){
cout << "Please enter your name!" << '\n';
cin >> name;
}
else {
cout << "now please type your lastname"<<'\n';
cin >> lastname;
if(lastname.length() == 0){
cout << "Please type your lastname" << '\n';
cin >> lastname;
}
else {
cout << "Now please enter your age" << '\n';
cin >> age;
if(age == -1){
cout << "Please enter your age" << '\n';
cin >> age;
}
}

}
cout << "Hello " << name << "(age" << age << ")" << '\n';
}
