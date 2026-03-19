#include <iostream>
#include <string>
using namespace std;
int main (){
string previous;
string current;
int repeatedword = 0;
while (cin >> current){
if(previous == current){
cout << "Repeated word:" << current << '\n';
++repeatedword;
}
if(current == "q"){
break;
}
previous = current;
}
cout << "repeated work count :" << repeatedword << '\n'; 

}
