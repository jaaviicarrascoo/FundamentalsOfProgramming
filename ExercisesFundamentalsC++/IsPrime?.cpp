#include <iostream>
using namespace std;

int main (){
int n;

cout<< "Input a number: "; cin>>n;

for (int i=2; i>=n; i++){
    
    if(n%i!=0) {
    cout<<n<<" Is not PRIME";}
    else{
        cout<<n<<" is PRIME"<<endl;}

}
return 0;
}