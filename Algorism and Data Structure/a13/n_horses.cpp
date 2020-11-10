#include <iostream>
#include <vector>
using namespace std;
const int N = 3;
typedef vector<vector<int>> Board;

void printBoard(vector<Board> solution, int n){
    for(int i=0; i<solution.size(); i++){
        cout << "Solution " << i+1 << ":" << endl;
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++)
                cout << solution[i][j][k] << " ";
            cout << endl;
        }
    }
}

bool isValid(Board board, int row, int col, int n){
    if(((row-1)>=0 && (col-2)>=0) && board[row-1][col-2])     //upper upper left
        return false;
    if(((row+1)<n && (col-2)>=0) && board[row+1][col-2])     //upper upper right
        return false;
    if(((row-2)>=0 && (col-1)>=0) && board[row-2][col-1])     //upper bottom left
        return false;
    if(((row+2)<n && (col-1)>=0) && board[row+2][col-1])     //upper bottom right
        return false;
    if(((row-2)>=0 && (col+1)<n) && board[row-2][col+1])     //bottom upper left
        return false;
    if(((row+2)<n && (col+1)<n) && board[row+2][col+1])     //bottom upper right
        return false;
    if(((row-1)>=0 && (col+2)<n) && board[row-1][col+2])     //bottom bottom left
        return false;
    if(((row+1)<n && (col+2)<n) && board[row+1][col+2])     //bottom bottom right
        return false;
    return true;
}

bool solveNHorse(Board board, int row, int col, int count, int n, vector<Board> &solution){
    if(count==n){
        solution.push_back(board);      // add board to solution
        return false;
    }
    if(col==n){
        col = 0;
        row +=1;
    }
    for(int i=row; i<n; i++){
        for(int j=col; j<n; j++){
            if(isValid(board, i, j, n)){    //check if the current position is valid
                board[i][j] = 1;
                count+=1;
                if(solveNHorse(board, i, j+1, count, n, solution)){
                    return true;
                }
                board[i][j] = 0;        //after adding to solution, wipe previous answer
                count-=1;
                col=0;
            }
        }
    }
    return false;
}

void solution(int n){
    Board board(N, vector<int>(n, 0));
    vector<Board> solution;
    solveNHorse(board, 0, 0, 0, n, solution);
    printBoard(solution, n);
}

int main(){
    solution(N);
}
