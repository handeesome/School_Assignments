#include <iostream>
#include <vector>
using namespace std;

int main(){
    string s;
    vector<string> v;
    while(s!="END"){
        getline(cin, s);
        if(s!="END")
            v.push_back(s);
    }
    if(v.size()>4){         //if both second and fifth element exist
        string temp;        //swap the elements
        temp = v[4];
        v[4] = v[1];
        v[1] = temp;
    }
    else
        cout << "either or both the second or the fifth element does not exist!" << endl;

    v.pop_back();
    v.push_back("???"); //replace the last element with ???

    for(int i=0; i<v.size(); i++){
        cout << v[i];
        if(i!=v.size()-1)
            cout << ',';        //separate by ,
    }

    cout << endl;//newline

    vector<string>::iterator it;
    for(it=v.begin(); it!=v.end(); it++){
        cout << *it;
        if(it!=v.end()-1)
            cout << ';';        //separate by ;
    }

    cout << endl;//newline

    vector<string>::reverse_iterator rit;
    for(rit=v.rbegin(); rit!=v.rend(); rit++){
        cout << *rit;
        if(rit!=v.rend())
        cout << ' ';            //separate by space in reverse order
    }


}


