#include <iostream>
#include <string>
#include <vector>
int main(){
	std::string input;
	int a = 0;
	std::vector<std::string> myvector;
	std::cout<<"Please type the string you wanted (cnrtl + d is quit)"<<std::endl;
	while(std::cin>>input){
		myvector.push_back(input);
		for(int i=0;i<myvector.size(); ++i){	std::cout<<a<<std::endl;
			if(i==0||a!=0){a+=1;
				
			
}		std::cout<<"Position: "<<a<<"char: "<<myvector[i]<<", ";
		}
		myvector.clear();
		if(myvector.empty()){
		}
	}

}
