#include <iostream>

template <class T>
class Stack{
    private:
        int size;
        T* arr;
        int amount;
    public:
        Stack();                //default constructor, 10
        Stack(const Stack&);    //copy constructor
        Stack(int);             //parametric constructor
        bool push (T element);  //push an element to the top of stack
        bool pop(T& out);       //pop out the top element
        T back(void);           //get the top element data
        int getNumEntries();    //num of elements
        ~Stack();               //destructor
};

template <class T>
Stack<T>::Stack():size(10){
    arr = new T[size];
    amount = 0;
}

template <class T>
Stack<T>::Stack(const Stack& a){
    size = a.size;
    arr = new T[size];
    for (int i=0; i<a.size; i++){
        arr[i] = a.arr[i];
    }
    amount = a.amount;
}

template <class T>
Stack<T>::Stack(int newsize):size(newsize), amount(0){
    arr = new T[newsize];
}

template <class T>
bool Stack<T>::push(T element){
    if(amount != size){
        arr[amount] = element;
        amount++;
        return true;
    }
    else
        return false;
}

template <class T>
bool Stack<T>::pop(T& out){
    if(amount!=0){
        out = arr[amount-1];
//        arr[amount-1] = NULL;
        amount--;
        return true;
    }
    else
        return false;
}

template <class T>
T Stack<T>::back(void){
    return arr[amount-1];
}

template <class T>
int Stack<T>::getNumEntries(){
    return amount;
}

template <class T>
Stack<T>::~Stack(){
    delete []arr;
}
