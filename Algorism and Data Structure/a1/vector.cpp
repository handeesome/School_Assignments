#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<string> noend;
    string word;
    while(word!="END"){
        cin >> word;
        if(word!="END")                 //the word END is not included in the vector
            noend.push_back(word);
    }

    for (int i=0; i<noend.size(); i++)
        cout << noend[i] << " ";

    //separate two outputs by a newline
    cout << endl;

    vector<string>::iterator v;
    for (v = noend.begin(); v!=noend.end(); v++){
        cout << *v;
        if(v!=noend.end()-1)            //the last word is not followed by a comma
            cout << ',';
    }
    return 0;
}
