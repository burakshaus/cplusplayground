#include <iostream>
#include <double>
#include <stdexcept>
using namespace std;
int main(){
int value= -1;
double voltage= -1.0
cout << "type a random number btw. 0-1023" << '\n';
try {
cin >> value;
if(value <= -1){
	throw std::invalid_argument("NOT GIVEN OR INVALID.");
}
else {
cout<< "Please type a random floating number btw 0.0-5.0"<<;
if(voltage <= -1.0 ){
throw std::invalid_argument("NOT GIVEN OR INVALI");
}
}

}
}catch(const std::invalid_argument&e){
std::cout<< "Exception handled:"<< e.what() << std::endl;
}
}
