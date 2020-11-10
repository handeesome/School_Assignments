#include <iostream>
#include <chrono>
#include "biginteger.h"
using namespace std;
using namespace std::chrono;
int NaiveRecursive(int n){
    if (n<2)                     //return 0 or 1
        return n;
    else{
        return NaiveRecursive(n-1)+NaiveRecursive(n-2); //add the previous two numbers
    }
}

int main(){
    int i=0;
    BigInteger n;
    int d = 0;
    while(d <10000 && i<10000){
        auto start = high_resolution_clock::now();
            n = NaiveRecursive(i);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop-start);
        d = duration.count();
        i++;
    }
    cout << "for index=" << i << " and time is" << d << ", loop stops" << endl;


}
