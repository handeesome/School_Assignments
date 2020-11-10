#include <iostream>
using namespace std;

int getMaxExp(int* A, int n){
    int Max = A[0];
    for(int i=1; i<n; i++){
        if(A[i]>Max){
            Max = A[i];         // find max in the array
        }
    }
    int Exp = 1;
    while(Max/Exp!=0){          // get highest digit position
        Exp *= 10;
    }
    return Exp/10;
}

//a recursive function using counting sort
void CountSort(int* A, int lower, int upper, int exp){
    int n = upper-lower+1;
    int temp[10] = {0};                         // exp is the significant bit of an int
    int sortarray[n];

    for(int i=lower; i<upper+1; i++){
        temp[(A[i]/exp)%10]++;                // normal counting sort steps
    }                                         // creates a counting array

    int temp2[10] = {0};                      // copy the above counting array
    for(int i=0; i<10; i++)                   // because it will be changed later
        temp2[i] = temp[i];


    for(int i=1; i<10; i++){
        temp[i] = temp[i-1] + temp[i];       // step two of normal counting sort
    }

    for(int i=upper; i>lower-1; i--){
        sortarray[temp[(A[i]/exp)%10]-1] = A[i];    // arrange the sorted array on an array
        temp[(A[i]/exp)%10]--;
    }

    for(int i=lower, j=0; i<upper+1; i++, j++){
        A[i] = sortarray[j];                    // and then revise the given array A
    }                                           // but sorted only according to exp

    int index = -1;
    for(int i=0; i<10; i++){
        index += temp2[i];                      // read the counting array and sort the unsorted parts only
        if(temp2[i]!=0 && temp2[i]!=1){         // 0 and 1 in counting array are in the right position
            CountSort(A, index-temp2[i]+1, index, exp/10);      // index become upper index in the
        }                                                   // next recursion
    }


}
// Radix Sort that sorts from the most significant bit to the least
// aka, the reverse order of the ordinary Radix Sort
void RadixSort(int* A, int n){
    int exp = getMaxExp(A, n);
    CountSort(A, 0, n-1, exp);
}

void print(int arr[], int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main(){
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66, 49};
    int n = sizeof(arr)/sizeof(arr[0]);
    RadixSort(arr, n);
    print(arr, n);
    return 0;
}
