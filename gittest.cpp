#include <iostream>
#include <vector>
int main(){
    std::vector<int> myvector;
    int input;
    std::cout<<"please type an integer followed by enter.";
    while(std::cin>>input){
    myvector.push_back(input);
    }
    for(int i:myvector){
        std::cout<<i<<"\t";
    }
}
