#include <iostream>
void square(int x){
int result = 0;
for(int i = 0; i<x;++i){
result += x;
}
std::cout<<"result is "<<result<<std::endl;
}
int main(){
square(6);
}
