/*
CH-230-B
a9 8.[c++]
Cenhan Du
cdu@jacobs-university.de
*/
#include <iostream>
using namespace std;
//compare first char with last first, and then keep comparing inwards
bool isPalindrome(string s){
    int length = s.length();
    for (int i=0, j=length-1; i<length/2; i++, j--){
        if(s[i]!=s[j]){
            return false;
        }
    }
    return true;
}
//keep entering a string, detects if its palindrome
//exits when "exit" is entered
int main(){
    bool tof = false;
    string s;
    while (tof==false){
        cin >> s;
        if (s=="exit"){
            tof = true;
        }
        if (isPalindrome(s)==true){
            cout << "The word is palindrome" << endl;
        }
        else {
            cout << "The word is not palindrome" << endl;
        }
    }
    return 0;
}
