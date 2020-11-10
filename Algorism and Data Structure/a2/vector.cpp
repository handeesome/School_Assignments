#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> v;
    for (int i=1; i<31; i++){
        v.push_back(i);             //fills the vector with int 1-30
    }
    v.push_back(5);                 //add 5 at the end

    reverse(v.begin(), v.end());    //reverse the vector

    vector<int>::iterator it;
    for(it=v.begin(); it!=v.end(); it++)
        cout << *it << ' ';             //print the vector
    cout << endl;
    replace(v.begin(), v.end(), 5, 129);    //replace every 5 with 129
    for (int value : v)
        cout << value << ' ';           //print the revised vector

    return 0;
}
