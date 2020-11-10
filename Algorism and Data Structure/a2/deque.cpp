#include <iostream>
#include <deque>
using namespace std;

int main(){
    deque<float> A;
    float temp;
    while(temp!=0){
        cin >> temp;
        if(temp>0)
            A.push_back(temp);          //if positive, add to end of deque
        else if(temp<0){
            A.push_front(temp);         //if negative, add to beginning of deque
        }
    }
    for(int value : A)
        cout << value << ' ';           //print deque A

    cout << endl;
    cout << endl;

    deque<float>::iterator it = A.begin();
    for(int i=0; i<A.size()/2; i++){
        it++;
        if(i==A.size()/2-1){
            A.insert(it, 0);                    //insert 0 in the middle
            i++;
        }
    }
    for(it = A.begin(); it!=A.end(); it++){
        cout << *it;
        if(it!=A.end()-1)
            cout << ';';                    //print deque A separates by ;
    }

    return 0;
}

