/*
CH-230-B
a13 p2.[c++]
Cenhan Du
cdu@jacobs-university.de
*/
#include <iostream>
#include <fstream>
using namespace std;

int main(){

    int n;
    cin >> n;//for n files
    string filename;//store the temp filename here
    string temp = "";//an empty string which will be filled with all of the file contents
    for (int i=0; i<n; i++){//loop n times
        cin >> filename;//get filenames from user
        ifstream file(filename);//open file in reading mode
        if(file.is_open()){//make sure file is opened
            while(!file.eof()){
                temp +=file.get();//add every line into string temp
            }
        }
        file.close();//close the file after every loop
        temp +="\n";//add a \n between each file
    }
    ofstream newfile("concatn.txt");//open concatn.txt in writing mode
    newfile << temp;//input the temp into concatn.txt

    return 0;
}
