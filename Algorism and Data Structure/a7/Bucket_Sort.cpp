#include <iostream>
#include <vector>
using namespace std;

void InsertionSort(vector<float> &A){
    int current;
    int i=0;
    vector<float>::iterator it;
    for(it = A.begin(); it<A.end(); it++){
        current = i;
        while(A[current]<A[current-1]){
            swap(A[current], A[current-1]);
            current--;
        }
        i++;
    }
}

void BucketSort(float* A, int n){
    vector<float> Bucket[n];
    for(int i=0; i<n; i++){
        Bucket[(int)(n*A[i])].push_back(A[i]);
    }
    for(int i=0; i<n; i++){
        InsertionSort(Bucket[i]);
    }
    vector<float>::iterator it;
    int index = 0;
    for(int i=0; i<n;i++){
        for(it = Bucket[i].begin(); it<Bucket[i].end();it++){
            A[index] = *it;
            index++;
        }
    }
}

int main(){
    float Array[7] = { 0.9, 0.1, 0.6, 0.7, 0.6, 0.3, 0.1};
    BucketSort(Array, 7);

    for(int i=0; i<7; i++){
        cout << Array[i] << endl;
    }
}
