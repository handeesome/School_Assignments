/*
CH-230-B
a9 p2.[c++]
Cenhan Du
cdu@jacobs-university.de
*/
#include <iostream>
using namespace std;
//print "s:x" n times on the string
int main(void){
    int n;
    double x;
    string s;
    cin >> n >> x >> s;
    for (int i=0; i<n; i++){
        cout << s << ":" << x << endl;
    }
    return 0;
}
