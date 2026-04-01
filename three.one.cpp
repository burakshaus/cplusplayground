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
				
			}
		}
		myvector.clear();
		if(myvector.empty()){
		std::cout<<"It's time for new string input. "<<std::endl;
		}else{
		std::cout<<"Something went wrong while clear the array. "<<std::endl;
		}
	}

}
