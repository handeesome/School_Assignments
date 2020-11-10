#include <iostream>
#include <stack>
using namespace std;

template <class T>
class Queue{
    private:
        stack<T> s1;        //stack 1, bottom is the oldest
        stack<T> s2;        //stack 2, for copying
    public:
        Queue();            // empty constructor
        void push(T x);
        T pop();            //pop and return the oldest element
};

template <class T>
Queue<T>::Queue(){}


template <class T>
void Queue<T>::push(T x){
    s1.push(x);
}

template <class T>
T Queue<T>::pop(){
    if(s1.empty()){
        cout << "Queue is empty!" <<endl;
        exit(0);
    }
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    T temp = s2.top();
    s2.pop();
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
    return temp;
}

int main(){
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;

}
