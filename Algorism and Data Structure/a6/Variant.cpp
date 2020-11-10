#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

int length = 500000;                    // length of the array
int Heap_Size;                      // size of the un-extracted heap

void Exchange(int *A, int i, int j){    //swap
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void Max_Heapify(int* A, int n){
    int l = 2*n+1, r = 2*n+2, largest;  //left index and right index number
    if(l<=Heap_Size && A[l]>A[n]){      // if left index exist in the heap
        largest = l;
    }
    else{
        largest = n;
    }
    if(r<=Heap_Size && A[r]>A[largest]){    //if right index exist
        largest = r;
    }
    if(largest != n){
        Exchange(A, n, largest);
        Max_Heapify(A, largest);            //swapping once is not enough
    }
}
void Build_Max_Heap(int* A){
    Heap_Size = length-1;
    for(int i=length/2-1; i>-1; i--){       //start from the last parent node
        Max_Heapify(A, i);
    }
}

int Float_down(int* A, int n){
    int l = 2*n+1, r = 2*n+2;  //left index and right index number
    if(r<=Heap_Size){      // if right index exist in the heap implied the left exist
        if(A[l]>A[r]){
            Exchange(A, n, l);
            return Float_down(A, l);
        }
        else{
            Exchange(A, n, r);
            return Float_down(A, r);
        }
    }
    else if(l<=Heap_Size){      // no need to compare, just exchange and return
        Exchange(A, n, l);
        return l;
    }
    return n;                   //return the index of base case
}
void Fixing_Step(int* A, int n){
    if (n%2==0){                    // if the number floated down to a even index
        if(A[n]>A[n/2-1]){          //  then its parent index should be n/2-1
            Exchange(A, n, n/2-1);
            Fixing_Step(A, n/2-1);
        }
    }
    else if(n%2==1){
        if(A[n]>A[n/2]){
            Exchange(A, n, n/2);
            Fixing_Step(A, n/2);
        }
    }
}

void HeapSort(int* A){
    Build_Max_Heap(A);
    for(int i=length-1; i>0; i--){          //extract every root to the end of the array
        Exchange(A, 0, i);
        Heap_Size = Heap_Size-1;
        Fixing_Step(A, Float_down(A, 0));
    }
}

void printA(int *A){
    for(int i=0; i<length; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

int main(){
    srand(time(NULL));
    int A[length];
    for(int i=0; i<100; i++){

        for(int i=0;i<length;i++){
            A[i] = rand()%length;
        }

        auto start = high_resolution_clock::now();
        HeapSort(A);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << duration.count() << endl;

    }
}
