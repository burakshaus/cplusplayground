#include <iostream>
#include <vector>
int main(){
    std::vector<int> myvector;
    int input;
    std::cout<<"please type an integer followed by enter.";
    while(std::cin>>input){
    myvector.push_back(input);
    }
    int sum;
    for(int i:myvector){
        sum+=i;
        std::cout<<i<<"\t";
    }
    std::cout<<"Sum of the elements: "<<sum<<std::endl;
}
