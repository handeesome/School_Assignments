#include <iostream>
#include <ctime>
#include <random>
using namespace std;
class pos{
    public:
        int row;
        int column;
        pos():row(0), column(0){}; //player starts from top left corner
};

class PuzzleBoard {
    private:
    // your choice
        int boardsize;
        int **field;        //puzzle board matrix
        pos current;        //current position
    public:
    // Subpoint (b)
    PuzzleBoard(int boardSize, int **fields = NULL);
    /* constructor should create the
    graph (as you defined it in subpoint (a) with the values from fields.
    If fields is null, then initialize the fields of the board with
    random values between 1 and boardSize-1. */
    bool makeMove(int direction);
    /* makes the move (if valid), direction is 0 for up, 1
    for right, 2 for down, 3 for left. Returns true if the move was
    valid, false otherwise. */
    bool getResult();
    /* Returns false if game is not over yet, true if puzzle was solved */
    friend std::ostream &operator<<(std::ostream &os, PuzzleBoard const &m);
    /* in Python, this is the __str__ method. */
    // Subpoint (c)
    int solve();
    /* returns the minimum number of moves needed to solve the puzzle,
    and -1 if it is not solvable. */
};
PuzzleBoard::PuzzleBoard(int boardSize, int **fields):boardsize(boardSize){
    if(fields==NULL){
        int *temp[boardSize];
        for(int i=0; i<boardSize; i++)
            temp[i] = new int[boardSize];
        srand(time(NULL));
        for(int i=0; i<boardSize; i++)
            for(int j=0; j<boardSize; j++)
                temp[i][j] = rand()%(boardSize-1)+1; //random between 1 and boardsize-1
        field = temp;
    }else
        field = fields;
}

bool PuzzleBoard::makeMove(int direction){
    int r = current.row;
    int c = current.column;
    switch (direction){
        case 0:                                 //up
            if(r - field[r][c]>=0){
                current.row = r-field[r][c];
                return true;
            }else
                return false;
            break;
        case 1:                                 //right
            if(c + field[r][c] <= boardsize-1){
                current.column = c+field[r][c];
                return true;
            }else
                return false;
            break;
        case 2:                                 //down
            if(r + field[r][c] <= boardsize-1){
                current.row = r+field[r][c];
                return true;
            }else
                return false;
            break;
        case 3:                                 //left
            if(c - field[r][c] >=-1){
                current.column = c-field[r][c];
                return true;
            }else
                return false;
            break;
    }
}

bool PuzzleBoard::getResult(){  //if the puzzle if solved
    if(current.row==boardsize-1 && current.column==boardsize-1)
        return true;
    else
        return false;
}

std::ostream& operator<<(std::ostream &os, PuzzleBoard const &m){ //output the puzzle board
    os << "Puzzle Board:" << endl;
    for(int i=0; i<m.boardsize; i++){
        for(int j=0; j<m.boardsize; j++)
            os << m.field[i][j] << " ";
        os << endl;
    }
}

main(){
    int A[5] = {1, 2, 1, 1, 2};
    int B[5] = {3, 1, 2, 1, 3};
    int C[5] = {2, 1, 1, 1, 1};
    int D[5] = {2, 1, 1, 2, 1};
    int E[5] = {4, 1, 3, 2, 1};

    int *puzzle[5] = {A, B, C, D, E};
    PuzzleBoard PB(5, puzzle);
    cout << PB;
    PB.makeMove(2);
    PB.makeMove(2);
    cout << PB.getResult();
    PB.makeMove(1);
    cout << PB.getResult();
}
