/*
CH-230-B
a9 5.[c++]
Cenhan Du
cdu@jacobs-university.de
*/
#include <iostream>
using namespace std;
//if the entered string is "quit", quit concatenating
//otherwise keep concatenating every string without space

int main(){
    string s, temp;
    bool tof = false;

        while (!tof){
            cin >> s;
            if (s=="quit"){
                cout << temp << endl;
                tof = true;
            }
            else{
                if(temp == ""){
                    temp = s;
                }
                else{
                    temp = temp + s;
                }
                tof = false;
            }
        }

    return 0;
}
