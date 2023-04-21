#include <iostream>
#include <array>
using namespace std;

const int NROW = 7;
const int NCOL = 7;

typedef array<int,NROW>TRows;
typedef array<TRows,NCOL>TMat;
void pascal (TMat& m);
void print (TMat m);

int main(){
    TMat TSqMat;
    pascal(TSqMat);
    print (TSqMat);
    return 0;
}
void initialize (TMat& m);
void pascal(TMat& m){
    int counter = 0;
    initialize(m);
    for(int i = 0; i < NROW; ++i){
        for(int j = 0; j < NCOL; ++j){
            if(i!=0 and j!=0 and j!=(NCOL-counter)){
                m[i][j] = (m[i][j-1]) + (m[i-1][j]);
            }

        }
        ++counter;
    }
}
void initialize (TMat& m){
    for(int i = 0 ;i<NROW ;++i){
        for(int j = 0 ;j<NCOL ;++j){
            if(i==0){
                m[i][j] = 1;
            }
           else if(j==0){
                m[i][j] = 1;
            }
            else {
                m [i][j] = 0;
            }
        }
    }

}
void print (TMat m){
    int counter = 0;
    for(int i=0; i<NROW; ++i){
        for(int j=0; j<(NCOL-counter); ++j){
            cout << m[i][j]<< " ";
        }
        cout<<endl;
        ++counter;
    }
}

