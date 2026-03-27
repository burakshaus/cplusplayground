#include <iostream>
using namespace std;
int square(int x){
return x*x;
}
int main(){
for(int i = 0; i<101; i++){
cout << i <<"\t"<<square(i)<<endl;
}
}
