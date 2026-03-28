#include <iostream>
#include <vector>
int main(){
	std::vector<int> vi;
	for(int i = 0; i<7; ++i){
	vi.push_back(i);
	std::cout<<vi[i]<<std::endl;
}
std::vector <int> v = {5,7,9,4,6,8};
for(int x:v){
	std::cout<<x<<std::endl;
}
std::vector<int> v0(5);
for(int i :v0){
	std::cout<<i<<std::endl;
}
}
