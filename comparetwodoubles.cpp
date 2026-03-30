#include <iostream>
int main(){
double in1, in2;
std::cout<<"Please type two floating numbers each followed by enter"<<std::endl;
while(std::cin>>in1>>in2){
if(in1=='|'||in2=='|'){
	std::cout<<"beep!"<<std::endl;
} else if(in1<in2){
	std::cout<<in1<<", "<<in2<<std::endl;
	}else if(in2<in1){
	std::cout<<in2<<", "<<in1<<std::endl;
	}else{
	std::cout<<in1<<","<<in2<<std::endl;
	}
	
}
}
