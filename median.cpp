#include <iostream>
#include <vector>
#include <algorithm>
int main(){
	std::vector<int> array;
	std::cout<<"Please type integers each followed by enter: "<<std::endl;
	int input;
	while(std::cin>>input){
		array.push_back(input);
	}

	std::ranges::sort(array);
	int size = array.size();
	int medianindex;
	if(size%2==0){
		medianindex=size/2;
	}else{
		medianindex=size/2+1;
	}
	std::cout<<"Median: "<<array[medianindex]<<std::endl;

}
