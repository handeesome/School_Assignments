#include <iostream>

template <class T>
struct DoubleList{
    T value;
    DoubleList<T>* previous;
    DoubleList<T>* next;
};

template <class T>
class List{
    private:
        DoubleList<T> *head; //pointer to the beginning of the list
        DoubleList<T> *tail; //pointer to the end of the list
    public:
        List();          //empty constructor
        ~List();         //destructor
        T returnfirst(); //return the first element without remove
        T removefirst(); //remove the first element and return it
        T returnlast();  //return the last element without remove
        T removelast();  //remove the last element and return it
        void addatfront(T element);  //add at the front of the list
        void addatend(T element);    //add at the end of the list
        int nodenum();               //returns the amount of elements in the list
};


template<class T>
List<T>::List(){
    head = NULL;
    tail = NULL;
}

template <class T>
List<T>::~List(){
    DoubleList<T>*temp = head;
    while(temp!=NULL){
        head = head->next;
        delete(temp);
        temp = head;
    }
}

template <class T>
T List<T>::returnfirst(){
    if(head==NULL){
        exit(1);
    }
    else
        return head->value;
}

template <class T>
T List<T>::returnlast(){
    if(tail==NULL){
        exit(1);
    }
    else
        return tail->value;
}

template <class T>
T List<T>::removefirst(){
    if(head==NULL){
        exit(1);
    }
    else{
        DoubleList<T>*temp = head;
        T tempvalue = head->value;
        head = head->next;
        delete(temp);
        head->previous = NULL;
        return tempvalue;
    }
}

template <class T>
T List<T>::removelast(){
    if(tail==NULL)
        exit(1);
    else{
        DoubleList<T>* temp = tail;
        T tempvalue = tail->value;
        tail = tail->previous;
        delete(temp);
        tail->next = NULL;
        return tempvalue;
    }
}

template <class T>
void List<T>::addatfront(T element){
    if(head==NULL){
        DoubleList<T>* temp = new DoubleList<T>;
        temp->value = element;
        temp->next = NULL;
        temp->previous = NULL;
        head = temp;
        tail = temp;
    }
    else{
        DoubleList<T>* temp = new DoubleList<T>;
        temp->value = element;
        temp->next = head;
        head->previous = temp;
        head = temp;
    }
}

template <class T>
void List<T>::addatend(T element){
    if(head == NULL)
        addatfront(element);
    else if(head->next==NULL){
        DoubleList<T>* temp = new DoubleList<T>;
        temp->value = element;
        temp->previous = head;
        head->next = temp;
        tail = temp;
    }
    else{
        DoubleList<T>* temp = new DoubleList<T>;
        temp->value = element;
        temp->previous = tail;
        tail->next = temp;
        tail = temp;
    }
}

template <class T>
int List<T>::nodenum(){
    int count = 0;
    DoubleList<T>* temp = head;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
