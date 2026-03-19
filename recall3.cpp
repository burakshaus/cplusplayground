#include <iostream>
#include <string>
using namespace std;
int main (){
string previous;
string current;
while (cin >> current){
if(previous == current){
cout << "Repeated word:" << current << '\n'; 
}
previous = current;
}


}
