#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;
int k = 100;          //the number of elements for doing Insertion Sort before merging
int n = 10000;          //the number of elements of the array needs sorting

void Insertion_sort(int* arr, int low, int high){   //low is lower bound, high is the upper bound
    int i = 1;                      // to keep tract of which numbers have been sorted
    while(i!=high-low){             // the loop stops when i is at the end of the array
        int l = low+i;              // when comparing, l is the second element
        int ptr = l-1;                      // and ptr is the one before that
        while(arr[l]<arr[ptr]){
            int temp = arr[l];      //swap two elements
            arr[l] = arr[ptr];
            arr[ptr] = temp;
            if(ptr!=low){           //if there are more elements to compare with, compare them
                l = ptr;
                ptr--;
            }
        }
        i++;
    }
}
//this Merge is for two parts of arrays to be sorted before merging
void Merge(int* arr, int low, int high, int mid){
    int l = low;
    int m = mid+1;
    int i = 0;
    int temp[high-low+1];   //create a temp array for the sorted array
    while(i!=(high-low+1)){



        if(m>high){             // if either part of the two are empty in terms to be put into temp
            while(l<mid+1){         // put the rest of the other part into temp
                temp[i] = arr[l];
                i++;
                l++;
            }
            break;
        }
        else if(l>mid){
            while(m<high+1){
                temp[i] = arr[m];
                m++;
                i++;
            }
            break;
        }


        if(arr[l]>arr[m]){          //compare the two elements in the respective position in each part
            temp[i] = arr[m];           // and put the smaller one into temp
            i++;
            m++;
        }
        else{
            temp[i] = arr[l];
            i++;
            l++;
        }
    }

    l = low;            //reset l as the lower bound
    i =0;               // and have a index tractor i
    while(l!=high+1){
        arr[l] = temp[i];       // copy every temp value into respective position in the actual array
        l++;
        i++;
    }
}
// divide each part into two for every sub-array
// until the base sub-array is smaller than or equal to k
void Merge_sort(int *arr, int low, int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;

        if(high-low+1>k){
            Merge_sort(arr, low, mid);
            Merge_sort(arr, mid+1, high);
        }
        else{
            Insertion_sort(arr, low, high);
        }
        Merge(arr, low, high, mid);
    }
}

int main(){
    srand(time(NULL));
    int averagecase[n];
    for(int i=0; i<n;i++){
        averagecase[i] = rand()%n+1;
    }

    int bestcase[n];
    for(int i=1; i<n+1; i++){
        bestcase[i-1] = i;
    }

    int worstcase[n];
    for(int i=0; i<n; i++){
        worstcase[i] = n-i;
    }

    auto start = high_resolution_clock::now();
        Merge_sort(averagecase, 0, n-1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken for this case: "
		<< duration.count() << " microseconds" << endl;

    return 0;

}
