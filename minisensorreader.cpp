#include <iostream>
#include <string>
#include <cmath>
#include <random>
#include <iomanip>
using namespace std;
int main(){
random_device rd;
mt19937 generator(rd());
uniform_int_distribution<int> distribution(0,1023);
int random_number = distribution(generator);
//cout <<"random number" << random_number<< '\n';
uniform_real_distribution<double> dis(0.0, 5.0);
double random_volt = dis(generator);
double casted = static_cast<double>(random_number);
double volt = casted/1023.0*5.0;
cout << fixed << setprecision(4);
cout << "the calculated value: " << volt <<"V" <<'\n';
};
