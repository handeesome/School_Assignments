#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

int length = 50000;                    // length of the array
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
void HeapSort(int* A){
    Build_Max_Heap(A);
    for(int i=length-1; i>0; i--){          //extract every root to the end of the array
        Exchange(A, 0, i);
        Heap_Size = Heap_Size-1;
        Max_Heapify(A, 0);
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
