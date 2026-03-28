#include <iostream>
#include <vector>
int main(){
	std::vector<int> myVector;
	for(int i = 0; i<4; ++i){
	myVector.push_back(i*2);
	}
	for(int i:myVector){
	std::cout<<i<<"\t"<<std::endl;
	}
	
}
