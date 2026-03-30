#include <iostream>
#include <vector>
int main(){
	std::string disliked = "Brocoli";
	std::vector<std::string> array;
	std::cout<<"Please type the strings that you want to add into the array (each followed by enter)"<<std::endl;
	for(std::string in; std::cin>>in;){
	if(in==disliked){
	std::cout<<"Beep"<<std::endl;
	}else{
	array.push_back(in);
	}
	
	}
}
