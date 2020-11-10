#include <iostream>
#include <chrono>
#include "biginteger.h"

using namespace std;
using namespace std::chrono;
BigInteger BottomUp(int n){
    if(n<2)
        return n;
    BigInteger first = 0, second = 1, temp;    //set initial first and second
    for(int i=1; i<n;i++){              // run a finite loop from bottom to up
        temp = first + second;          // add the previous two numbers add get the next one
        first = second;
        second = temp;
    }
    return temp;
}

int main(){
    int i=0;
    BigInteger n;
    int d = 0;
    while(d <10000 && i<10000){
        auto start = high_resolution_clock::now();
            n = BottomUp(i);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop-start);
        d = duration.count();
        i++;
    }
    cout << "for index=" << i << " and time is" << d << ", loop stops" << endl;

}
