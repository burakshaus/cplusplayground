#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
vector<double> doubles;
vector<string> units;
cout<<"Please type floating points and unit followed by enter:"<<endl;
double input;
string unit;
double sum;
vector<double> meterdoubles;
while(cin>>input>>unit){
if(unit=="m"){
meterdoubles.push_back(input);
doubles.push_back(input);
units.push_back(unit);
sum+=input;
}else if(unit=="in"||unit=="inch"){
input/=2.54;
doubles.push_back(input);
units.push_back(unit);
}else if(unit=="f"||unit=="feet"){
input/=0.48;
doubles.push_back(input);
units.push_back(unit);
}else if(unit=="cm"||unit=="centimeter"){
input/=10;
doubles.push_back(input);
}else{
cout<<"Unvalid unit entered. "<<endl;
}

}
cout<<"Total values: "<<endl;
cout<<"Sum: "<<sum<<endl;
cout<<"number of values: "<<units.size()<<endl;
for(int i = 0; i<units.size(); ++i){
cout<<doubles[i] <<" "<<units[i]<<"."<<endl;
}
}
