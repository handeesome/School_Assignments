#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;


void SelectionSort(int arr[], int size){
    int current, min;
    for(int i=0; i<size; i++){
        current = i;                        // The loop invariant is size
        min = i;                            // at the beginning and the end of each iteration
        for(int j=0; j<size-i-1; j++){      // size does not change
            current++;
            if(arr[min]>arr[current])       // This shows the algorithm is correct in terms of the size of the array
                min = current;
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}


int main(){
    srand(time(0));
    int n;
    cin >> n;
    int* arr = new int(n);
    for (int i =0; i<n; i++){
        arr[i] = rand()%10000+1;
    }

//    int* caseA = new int(n);
//    for(int i = 1 ; i < n ; i++){       // if n = 5, caseA is 5 1 2 3 4
//        caseA[i] = i;                   // with every element misplaced, which leads to n-1 swaps
//    }arr[0] = n;
//
//    int* caseB = new int(n);            // if n = 5, caseB is 1 2 3 4 5
//    for(int i = 1 ; i <= n ; i++){      // which is sorted already, and this has 0 swaps
//        caseB[i-1] = i;
//    }

//    auto start = high_resolution_clock::now();
//    SelectionSort(arr, n);
//    auto stop = high_resolution_clock::now();
//    auto duration = duration_cast<microseconds>(stop - start);
//    cout << duration.count() << endl;

    auto start = std::chrono::system_clock::now();
    SelectionSort(arr, n);
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count()*100000 << "s\n";

    for(int i=0; i<n; i++)
        cout << arr[i] << ' ';

    return 0;
}
