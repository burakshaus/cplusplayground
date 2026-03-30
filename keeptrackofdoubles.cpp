#include <iostream>
int main(){
double smallest, largest, input;
std::cout<<"type floating number that you want (followed by enter) and type non number char to quit"<<std::endl;
std::cin>>input;
smallest = input;
largest= input;
while(std::cin>>input){
if(input<smallest){
smallest = input;
}else if(input>largest){
largest=input;
}

}
std::cout<<"smallest: "<<smallest<<" largerst: "<<largest<<std::endl;
}
