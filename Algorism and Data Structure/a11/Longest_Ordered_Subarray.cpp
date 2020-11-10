#include <iostream>
#include <vector>
using namespace std;

void Print_LOS(int* A, int length){
    vector<vector<int>> solution(length);   //vectors for dynamic programming
    solution[0].push_back(A[0]);            //push first num into first vector
    if(A[1]<A[0])
        solution[1].push_back(A[1]);        // in case A[1] smaller than A[0] which causes solution[1] empty
    for(int i=1; i<length; i++){
        for(int j=0; j<i; j++){
            if(A[i]>A[j] && solution[i].size()<solution[j].size()+1){   //if bigger and is current optimal solution
                solution[i] = solution[j];
                solution[i].push_back(A[i]);
            }
        }
    }
    vector<int> max = solution[0];
    for(vector<int> i : solution){      //find longest vector
        if(i.size()>max.size())
            max = i;
    }
    for(int i : max)                    //print
        cout << i << " ";

}

int main(){
    int A[11] = {8, 3, 6, 50, 10, 8, 100, 30, 60, 40, 80};
    Print_LOS(A, 11);

    return 0;
}
