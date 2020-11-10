#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
class Node {
    public:
        int key;
        int value;
        Node(int key, int value);
};
class HashTable {
    private:
        Node **arr;
        int maxSize;
        int currentSize;
        int Collision;              //for Collision amount test
    public:
        HashTable();
        int hashCode(int key);                      //hash function
        void insertNode(int key, int value);        //insert a couple to the table
        int get(int key);                           //get value by given key
        bool isEmpty();                             //return whether table is empty
        void print(){
            for(int i=0; i<maxSize; i++){
                if(arr[i] != NULL && arr[i]->key != -1)
                    cout << "key = " << arr[i]->key
                         <<"  value = "<< arr[i]->value << endl;
            }cout << Collision;
        }
};

Node::Node(int key, int value):key(key), value(value){}

HashTable::HashTable(){
    arr = new Node*[maxSize];
    for(int i=0; i<maxSize; i++)
        arr[i] = NULL;
    maxSize = 10;
    currentSize = 0;
    Collision = 0;
}

int HashTable::hashCode(int key){
    return key % 7;
}

void HashTable::insertNode(int key, int value){
    Node *temp = new Node(key, value);
    int index = hashCode(key);
    while(arr[index]!=NULL){
        index++;
        index %= maxSize;
        Collision++;
    }
    arr[index] = temp;
    currentSize++;
}

int HashTable::get(int key){
    int index = hashCode(key);
    int count = 0;
    while(arr[index]!=NULL){
        count++;
        if(count > maxSize){
            cout << "This key is not found in HashTable!" << endl;
            return -1;
        }
        if(arr[index]->key==key)
            return arr[index]->value;
        index++;
        index %= maxSize;
    }
    cout << "This key is not found in HashTable!" << endl;
    return -1;
}

bool HashTable::isEmpty(){
    if(currentSize==0)
        return true;
    return false;
}

int main(){
    HashTable *h = new HashTable;
    srand(time(NULL));
    for(int i=0; i<10; i++)
        h->insertNode(rand(), 1);
    h->print();
    return 0;
}
