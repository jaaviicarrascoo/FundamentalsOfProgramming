#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n, sum = 0, elev = 0;

    cout << "Sum from type 2^1 + 2^2 + ... + 2^n" << endl;

    cout << "Input number of digits to compute the sum: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        elev = pow(2, i);
        sum += elev;
    }

    cout << "\nThe sum is: " << sum << endl;

    return 0;
}
