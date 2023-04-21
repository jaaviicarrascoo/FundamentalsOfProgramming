#include <iostream>
using namespace std;

int main() {

int n,x=0,y=1,z=1 ;
do
{
    cout << "Input the digits of the serie: ";
    cin >> n;
} while (n <= 0);

for (int i = 1; i < n; i++)
{
    z=x+y;
    cout <<z<<" ";
    x=y;
    y=z;

}

cout<<n<<endl;

return 0;
}

