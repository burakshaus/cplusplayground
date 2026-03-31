#include <iostream>
#include <vector>
int main(){
	std::cout<<"Please type foaling points each followed by enter"<<std::endl;
	std::vector<double> array;
	double input;
	double sum,smallest,largest;
	std::string unit;
	while(std::cin>>input){
		array.push_back(input);
		if(input<smallest){
		smallest = input;
		}
		if(input>largest){
		largest = input;
		}
		std::cout<<"Please enter the unit (e.g. cm, in,m,ft) "<<std::endl;
		std::string unit;
		std::cin>>unit;
		if(unit=="m"){
			sum+=input;
		}
		std::cout<<"Now it's turn for ploatint point"<<std::endl;
	}
	std::cout<<"Smallest: "<<smallest<<" Largest: "<<largest<<" number of values:"<<array.size()<<std::endl;

}
