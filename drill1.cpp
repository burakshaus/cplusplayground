#include <iostream> 
#include <string>
using namespace std; 
int main (){
string first_name; 
cout << "could you please type your firstname" << '\n';
cin >> firstname;
cout << "Dear, " << first_name << ". How are you i am fine thanks, i miss you my friend "<< '\n';  
string friend_name; 
cout << "enter your fiend's name" << '\n';
cin >> friend_name; 
int age ;
cout << "Have you seen " << friends_name << "lately?" << '\n';
cout << "enter your age"; 
cin >> age ; 
cout << "I hear you just had a birthday and you are " << ++age << "years old" << '\n';
if(age <= 0 && age >= 110){
simple_error("you're kissing !");
}
if(age < 12){
cout "You will be " << age+1 << "next year" << '\n'; 
}else if(age == 17){
cout << "Next year you will be able to vote" << '\n';
}
else if (age>70){
cout cout "Are you retired?" << '\n';
}
cout " Yours sincerely,\n\n Ahmet Burak Can"; 
}
int simple_error(string message){
cout << message << '\n'; 

}
