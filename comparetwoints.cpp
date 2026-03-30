#include <iostream>
int main(){
int in1,in2;
std::cout<<"Please type two integers followed by an enter"<<std::endl;
while(std::cin>>in1>>in2){
if(in1<in2){
	std::cout<<in1<<", "<<in2<<std::endl;
}else if(in2<in1){
	std::cout<<in2<<", "<<in1<<std::endl;
}else{
	std::cout<<"Both are aqual"<<in1<<","<<in2<<std::endl;
}
}

}
