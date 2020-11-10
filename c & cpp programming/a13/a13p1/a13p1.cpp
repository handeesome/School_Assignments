/*
CH-230-B
a13 p1.[c++]
Cenhan Du
cdu@jacobs-university.de
*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(){

    string filename;//filename
    cin >> filename;
    ifstream a;//create a file
    a.open(filename, ios::in);//name the file as the filename

    string newname = filename.substr(0, filename.length()-4);//get rid of the last 4 chars
    newname = newname + "_copy.txt";//concat with _copy.txt

    ofstream b;//crate a new file
    b.open( newname, ios::out);//open it with the newname

    b << a.rdbuf();//copy the old to new

  return 0;
}
