#include <iostream>
#include <chrono>
#include <math.h>
using namespace std;
using namespace std::chrono;
float power(float number, int p){
    if(p==0){
        return 1;
    }
    if(p%2==1){
        if(p!=1){
            float sum = power(number,p/2)*power(number,p/2);
            return sum*number;
        }
        else{
            return number;
        }
    }
    else{
        if(p!=1)
            return power(number, p/2)*power(number, p/2);
        else{
            return number;
        }
    }
}
int ClosedForm(int n){
    return (power((1+sqrt(5))/2,n))/sqrt(5);//golden ratio to power of n
                                          //over sqrt of 5
}

int main(){
    int i=0;
    long long n;
    int d = 0;
    while(d <10000 && i<10000){
        auto start = high_resolution_clock::now();
            n = ClosedForm(i);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop-start);
        d = duration.count();
        i++;
    }
    cout << "for index=" << i << " and time is" << d << ", loop stops" << endl;

    for(int i=0; i<45;i++)
        cout << ClosedForm(i) <<endl;

}
