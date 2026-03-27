#include <iostream>
void print_square(int);;
void print_square(int x){
	std::cout<<x*x<<std::endl;
}
int main(){
for(int i = 0; i<100; ++i){
print_square(i);
}
}
