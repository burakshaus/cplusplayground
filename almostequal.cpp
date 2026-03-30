#include <iostream>
int main(){
double in1, in2,difference;
while(std::cin>>in1>>in2){
	if(in1>in2){
		difference = in1-in2;
		if(difference<0.001){
			std::cout<<"They are almost equal"<<std::endl;

		}
	}else if(in2>in1){
		difference = in2-in1;
	if(difference<0.001){
	std::cout<<"They are almost equal"<<std::endl;
	}
	}
}
}
