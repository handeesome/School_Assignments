/*
CH-230-B
a9 p3.[c++]
Cenhan Du
cdu@jacobs-university.de
*/
#include <iostream>
using namespace std;
//compute the absolute value a number
float absolute(float num){
    if (num>0){
        return num;
    }
    else{
        return 0-num;
    }
}
int main(){
    float num;
    cin >> num;
    cout << absolute(num) << endl;

    return 0;
}
