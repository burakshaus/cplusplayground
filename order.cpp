#include <iostream> 
#include <string>
using namespace std;
int main () {
cout << "Please enter three number followed by enter" << '\n';
int a,b,c;
cin>>a>>b>>c;
if(a==b==c){
cout<<a<<","<<b<<","<<c<<'.';
}else if(a<b&&a<c){
cout<<a<<",";
if(b<c){
cout<<b<<","<<c<<".\n";
}else {
cout<<c<<","<<b<<".\n"<<'.';
}
}else if(b<<a&&b<c){
cout<<b<<",";
if(a<c){
cout<<a<<","<<c<<".\n";
}else{
cout<<c<<","<<a<<".\n";
}
}else if(c<a&&c<b){
cout<<c<<",";
if(b<a){
cout<<b<<","<<a<<".\n";
}else{
cout<<a<<","<<b<<".\n";
}
}
}
