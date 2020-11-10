#include <iostream>
#include <vector>
using namespace std;

void Sum_Triangle(int **A, int level){
    vector<vector<int>> temp(level);
    temp[0].push_back(A[0][0]);
    for(int i=1; i<level; i++){
        for(int j=0; j<i+1; j++){
            if(j==0){
                temp[i].push_back(A[i][j]+temp[i-1][j]);        // nodes on the sides of the triangle
            }                                                   // only have one possible outcome
            else if(j==i){
                temp[i].push_back(A[i][j]+temp[i-1][j-1]);
            }
            else{                                               // nodes in the middle can choose from
                int left = temp[i-1][j-1];                      // two above it
                int right = temp[i-1][j];
                temp[i].push_back(max(left, right)+A[i][j]);
            }
        }
    }
    int m = temp[level-1][0];       //m is the max of the last line in modified triangle
    int num=0;                      //num is the position of the node on the right path
    for(int i=0; i<level; i++){
        if(m<temp[level-1][i]){
            m = temp[level-1][i];
            num = i;
        }
    }

    cout << m << endl;              //print sum of the right path

    int solution[level];
    for(int i=level-1; i>-1; i--){
        if(num==0)
            solution[i] = A[i][num];
        else{
            solution[i] = A[i][num];
            if(temp[i-1][num-1]>temp[i-1][num])
                num--;
        }
    }

    for(int i=0; i<level; i++)      //print solution for the paths
        cout << solution[i] << " ";
}

int main(){

    int A[] = {7};
    int B[] = {3, 8};
    int C[] = {8, 1, 0};
    int D[] = {2, 7, 4, 4};
    int E[] = {4, 5, 2, 6, 5};
    int *F[5] = {A, B, C, D, E};

    Sum_Triangle(F, 5);
}
