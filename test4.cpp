#include <iostream>
#include <vector>
int main(){
	std::cout<<"Please enter integers (crtl+d to quit)";
	std::vector<int> myarray;
	int input;
	while(std::cin>>input){
	myarray.push_back(input);
	}

}
