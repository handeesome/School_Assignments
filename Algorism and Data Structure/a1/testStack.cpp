#include "Stack.h"
using namespace std;
int main(){
    //test for default constructor
    Stack<int> ints;

    //test for parametric constructor
    Stack<double> doubles(20);

    //test for push
    for (int i=0; i<10; i++){
        doubles.push(i*1.1);
    }
    cout << doubles.back() << endl; //should be 9.9

    //test for pop
    double out;
    for (int i=0; i<5; i++){
        doubles.pop(out);
    }
    cout << out << endl; //should be 5.5

    //test for getNumEntries
    cout << doubles.getNumEntries() << endl; //should be 5

    return 0;
}
