#include <iostream>
#include <map>
#include <fstream>
#include <exception>
using namespace std;

int main(){
    ifstream file;
    file.open("data.txt");          //open file with input mode

    map<string, string> m;
    pair<string, string> person;    //create a pair

    while(!file.eof()){
        getline(file, person.first);
        getline(file, person.second);
        m.insert(person);           //insert every two lines into map
    }


    cout << "Please enter a name: " << endl;
    getline(cin, person.first);             //get name
    try{
        cout << "This is the corresponding birthday: " << m.at(person.first) << endl;  //print birthday
    }
    catch(exception e){
        cerr << "Name not found!" << '\n';  //if no such name
    }

    return 0;
}

