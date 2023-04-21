#include <iostream>
using namespace std;

int main(){

int x,fact=1;
cout << "Input a number" << endl; cin>>x;

for (int i = 1; i <= x; i++)
{fact*=i;}

cout <<x<<"! is "<<fact<<endl;
}

