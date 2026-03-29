#include <iostream>
#include <vector>
int main(){
	std::cout<<"Please enter double values followed by enter"<<std::endl;
	std::vector<double> myVector;
	for(double temp; std::cin>>temp;){
	myVector.push_back(temp);
	}
	for(double i: myVector){
	std::cout<<i<<"\t"<<std::endl;
	}
}
