#include <iostream>
using namespace std;

template <class T>
class Stack{
    private:
        struct StackNode{
            T data;
            StackNode *next;
        };
        StackNode* top;         // top of stack
        int size;               // -1 if not set, value otherwise
        int current_size;       // unused if size = -1
    public:
        void push(T x);         // if size set, check for overflow
        T pop();                // return element if not in underflow
        bool isEmpty();         // true if empty, false otherwise
        Stack(int new_size);
        Stack();
};

template <class T>
Stack<T>::Stack() : size(-1), current_size(-1){
    top = NULL;
}

template <class T>
Stack<T>::Stack(int new_size) : size(new_size), current_size(-1){
    top = NULL;
}

template <class T>
void Stack<T>::push(T x){
    if(current_size>=size){
        cout << "Stack Overflow!" << endl;
    }else{
        StackNode *temp = new StackNode;
        temp->data = x;
        temp->next = top;
        top = temp;
        current_size +=1;
    }
}

template <class T>
T Stack<T>::pop(){
    if(isEmpty()){
        cout << "Stack Underflow!" << endl;
        return 0;
    }else{
        T temp = top->data;
        top = top->next;
        current_size -=1;
        return temp;
    }
}

template <class T>
bool Stack<T>::isEmpty(){
    if(current_size<=-1)
        return true;
    else
        return false;
}

int main(){
    Stack<int> s(2);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    int a;
    for(int i=0; i<4; i++){
    a = s.pop();
    cout << a << endl;
    }
}
