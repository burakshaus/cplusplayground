#include <iostream>
#include <algorithm>
#include <vector>
int main(){
	std::cout<<"please enter the eşements of the array each element followed by enter"<<std::endl;
	std::vector<int> array;
	int i;
	std::cout<<"enter a non number character to quit the loop"<<std::endl;
	while(std::cin>>i){
		array.push_back(i);

	}
	std::cout<<"Array= ";
	for(int i:array){
		std::cout<<i<<", ";
	}
	std::cout<<'\n';
	std::ranges::sort(array);
	std::cout<<"Median of the array is :"<<array[array.size()/2]<<std::endl;
}
