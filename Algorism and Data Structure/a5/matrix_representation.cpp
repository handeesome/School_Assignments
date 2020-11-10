#include <iostream>
#include <chrono>
#include "biginteger.h"
using namespace std;
using namespace std::chrono;
void MatrixMultiply(BigInteger M[2][2], BigInteger N[2][2]){
    BigInteger a = M[0][0]*N[0][0]+M[0][1]*N[1][0];        // do matrix multiplication
    BigInteger b = M[0][0]*N[0][1]+M[0][1]*N[1][1];
    BigInteger c = M[1][0]*N[0][0]+M[1][1]*N[1][0];
    BigInteger d = M[1][0]*N[0][1]+M[1][1]*N[1][1];

    M[0][0] = a;                                    // copy after every node is calculated
    M[0][1] = b;
    M[1][0] = c;
    M[1][1] = d;
}
void MatrixPower(BigInteger arr[2][2], int n){
    BigInteger M[2][2] = {{1,1},{1,0}};
    for(int i=2; i<n;i++){          // matrix to the power of n
        MatrixMultiply(arr, M);
    }
}
BigInteger MatrixRepresentation(int n){
    BigInteger M[2][2] = {{1,1},{1,0}};    //      n
    MatrixPower(M, n);              // [1 1]
    return M[0][0];                 // [1 0]
}

int main(){
    int i=0;
    BigInteger n;
    int d = 0;
    while(d <10000 && i<10000){
        auto start = high_resolution_clock::now();
            n = MatrixRepresentation(i);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop-start);
        d = duration.count();
        i++;
    }
    cout << "for index=" << i << " and time is" << d << ", loop stops" << endl;
}
