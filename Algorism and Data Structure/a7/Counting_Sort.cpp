#include <iostream>
using namespace std;

int Max(int* A, int n){
    int Max = 0;
    for(int i=0; i<n; i++){
        if(A[i]>Max){
            Max = A[i];
        }
    }
    return Max;
}
void Countsort(int* A, int length){

    int* temp;
    int LOT = Max(A, length);       //find the biggest value in A
    temp = new int[LOT+1];            // and make it the size of temp +1

    for(int i=1; i<LOT+1; i++){       // set every value of temp 0
        temp[i] = 0;
    }

    for(int i=0; i<length; i++){    // increment index of temp with respective value in A
        temp[A[i]] += 1;
    }

    for(int i=2; i<LOT+1; i++){
        temp[i] = temp[i-1]+temp[i];    // add the previous node to the current one in temp
    }

    int* sortarray = new int[length];
    for(int i=length-1; i>-1; i--){     // put every value in the corresponding position
        sortarray[temp[A[i]]-1] = A[i];
        temp[A[i]]--;                   // decrement after the position is used
    }

    for (int i=0; i<length; i++){
        A[i] = sortarray[i];        // copy the sorted array into the initial array
    }
}

int main(){
    int Array[7] = {9, 1, 6, 7, 6, 2, 1};
    Countsort(Array, 7);
    for(int i=0; i<7; i++){
        cout << Array[i] << endl;
    }
}
