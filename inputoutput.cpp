#include <iostream>

using namespace std;

int main() {
    char fname[20]; 
    char sname [20];
    
    cout << "Enter your first name: " << std::endl;
    cin.getline(fname, 20); 
    cout << "Your first name is: " << fname << std::endl;
    cout << "enter your second name:"<<std::endl;
    cin.getline(sname,20);
    cout<<"Your second name is : "<<sname<<std::endl;
    return 0;
}
