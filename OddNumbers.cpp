
#include <iostream>
#include <array>
using namespace std;
const int NROW = 3;
const int NCOL = 4;

typedef array <int,NCOL> TRow;
typedef array <TRow, NROW> TMatrix;

//typedef array<array<int, NCOL>, NROW> TMatrix;
int addOddLargests(TMatrix m);
void print(TMatrix m);

int main()
{
    TMatrix m = {{{{6, 4, 12, 2}},
                  {{8, 2, 7, 3}},
                  {{4, 1, 6, 2}}}};
    // display matrix
    cout << "The contents of the matrix is:" << endl;
    print(m);
    // check addOddLargests
    int sum = addOddLargests(m);
    cout << "The sum of the largests odd number per row is: " << sum << endl;
    return 0;
}

int greaterOddRow(TRow t);

// returns the sum of the largest odds for every row
int addOddLargests(TMatrix m){
    int sum = 0;
    for(int i = 0; i < NROW;i++){
        sum += greaterOddRow(m[i]);
    }
    return sum;
}


 int greaterOddRow(TRow t)
{
    int odd = 0;

    for (int i =0;i<NCOL; i++){
        if(t[i]%2!=0 and t[i]>odd){
            odd = t[i];
        }
    }
    return odd;
}

// display the matrix
void print(TMatrix m)
{
    for (int r = 0; r < NROW; r++)
    {
        for (int c = 0; c < NCOL; c++)
            cout << m[r][c] << " ";
        cout << endl;
    }
    cout << endl;
}