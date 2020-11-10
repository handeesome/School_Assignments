/*
CH-230-B
a9 4.[c++]
Cenhan Du
cdu@jacobs-university.de
*/
#include <iostream>
#include <stdio.h>
using namespace std;
//if the parameters are two integers, return the difference
int mycount(int a, int b){
    return b-a;
}
//count the number of occurrences of a char in a string
int mycount(char c, string s){
    int temp=0;
    int length = s.length();
    for (int i=0; i<length; i++){
        if (s.length()==0){
            return 0;
        }
        if (s[i]==c){
            temp++;
        }
    }
    return temp;
}

int main(){
    int a, b;
    char c;
    string s;

    cout << "Please enter two integers: " << endl;
    cin >> a >> b;
    cout << mycount(a, b) << endl;

    cout << "Please enter a char first and then a string: " << endl;
    cin >> c;
    getchar();
    getline(cin, s);
    cout << mycount(c, s) << endl;

    return 0;
}
