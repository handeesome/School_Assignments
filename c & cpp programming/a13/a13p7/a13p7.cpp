/*
CH-230-B
a13 p7.[c++]
Cenhan Du
cdu@jacobs-university.de
*/
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
int main(){
    vector<int> a(20, 8);//create a int vector with 20 of 8
    try{
        a.at(21);//try to get the value of the 21 element
    }
    catch(const out_of_range &a){
        cerr << "out of range: " << a.what() << "\n";//use what() to printout the error message
    }
}
