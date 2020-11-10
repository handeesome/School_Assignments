#include <iostream>
#include <list>
#include <fstream>

using namespace std;
int main(){
    list<int> A, B;
    int temp;

    while(temp>0){
        cin >> temp;
        if (temp<=0)
            break;
        A.push_back(temp);      //insert int at end of A
        B.push_front(temp);     //insert int at beginning of B
    }
    for(int value : A)
        cout << value << " ";   //print A

    ofstream file;
    file.open("listB.txt");
    for(int value : B)
        file << value << " ";   //print B in listB.txt
    file.close();

    cout << endl;
    cout << endl;

    temp = A.front();           //move first int to the end
    A.pop_front();
    A.push_back(temp);

    temp = B.front();           //same here
    B.pop_front();
    B.push_back(temp);

    list<int>::iterator it;
    for(it = A.begin(); it!=A.end();it++){
        cout << *it;
        if(it!=A.end())
            cout << ',';
    }
    for(it = B.begin(); it!=B.end();){
        cout << *it;
        it++;                               //print list A and B separate by ,
        if(it!=B.end())
            cout << ',';
    }
    cout << endl;
    cout << endl;

    A.merge(B);                             //merge A and B
    A.sort();                               //print the sorted list
    for (int value : A)
        cout << value << ' ';

    return 0;
}
