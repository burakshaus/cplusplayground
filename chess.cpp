#include <iostream>
int main(){
int numberofsquares = 0;
double grains = 1000;
for(int i = 1; i<=8; i*=2){
std::cout<<"initial grains: "<<grains<<std::endl;
for(int j = 0; j<8; ++i){
numberofsquares++;
grains-i;
}
std::cout<<"remeaning grains : "<<grains<<" numberofsquares: "<<numberofsquares<<std::endl;
if(grains==0){
grains *=10;
}
}


}
