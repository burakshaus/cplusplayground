#include <iostream>
#include <vector>
#include <algorithm>
int main(){

	std::vector<int> array= {9,8,7,6,5,4,3,2,1,};
	std::ranges::sort(array);
	for(int i:array){
	std::cout<<i<<", ";
	}
	std::cout<<'\n';

}
