#include <iostream>
#include <ctime>
#include <random>
#include <queue>
using namespace std;

const int INF = 999999;
const int size = 5;
class pos{
    public:
        int row;
        int column;
        char color = 'w'; //white for non discovered, black for discovered
        pos():row(0), column(0){}; //player starts from top left corner
};

class PuzzleBoard {
    private:
    // your choice
        int boardsize;
        int **field;        //puzzle board matrix
        pos current;        //current position
        queue<pos> Q;
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
    void repeat(int direction, pos temp, int r, int c, int **level);
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

int PuzzleBoard::solve(){
    int *level[boardsize];              // for level track
    for(int i=0; i<boardsize; i++)
        level[i] = new int[boardsize];
    for(int i=0; i<boardsize; i++)
        for(int j=0; j<boardsize; j++)
            level[i][j] = INF;          //make every node infinite

    int *discover[boardsize];           //determine if a node is discovered or not
    for(int i=0; i<boardsize; i++)
        discover[i] = new int[boardsize];
    for(int i=0; i<boardsize; i++)
        for(int j=0; j<boardsize; j++)
            discover[i][j] = INF;          //make every node infinite


    level[0][0] = 0;    //starting node has level 0
   // queue Q;
    Q.push(current);
    while(!Q.empty()){
        pos temp = Q.front();
        int r = temp.row;
        int c = temp.column;
        if(discover[r][c]==1){
            Q.pop();
            continue;
        }else if(r==boardsize-1 && c==boardsize-1)
            return level[r][c];
        if(r==0){
            if(c==0){               //top left corner
                current = temp;
                if(makeMove(1)){
                    level[current.row][current.column] = 1;
                    Q.push(current);
                }
                current = temp;
                if(makeMove(2)){
                    level[current.row][current.column] = 1;
                    Q.push(current);
                }
            }
            else if(current.column==boardsize-1){    // top right corner
                repeat(3, temp, r, c, level);
                repeat(2, temp, r, c, level);
            }else{                              //top side
                repeat(3, temp, r, c, level);
                repeat(2, temp, r, c, level);
                repeat(1, temp, r, c, level);
            }
        }else if(r==boardsize-1){
            if(c==0){                           //button left corner
                repeat(0, temp, r, c, level);
                repeat(1, temp, r, c, level);
            }else{                              //button side
                repeat(3, temp, r, c, level);
                repeat(0, temp, r, c, level);
                repeat(1, temp, r, c, level);
            }
        }else if(c==0){                         //left side
            repeat(0, temp, r, c, level);
            repeat(1, temp, r, c, level);
            repeat(2, temp, r, c, level);
        }else if(c==boardsize-1){               //right side
            repeat(0, temp, r, c, level);
            repeat(3, temp, r, c, level);
            repeat(2, temp, r, c, level);
        }else{                                  //middle part
            repeat(0, temp, r, c, level);
            repeat(1, temp, r, c, level);
            repeat(2, temp, r, c, level);
            repeat(3, temp, r, c, level);
        }
        discover[r][c] = 1;
        Q.pop();
    }
    return -1;//not solvable
}

void PuzzleBoard::repeat(int direction, pos temp, int r, int c, int** level){
    current = temp;
    if(makeMove(direction)){                //compare current level with new level
        if(level[current.row][current.column]>level[r][c]+1)
            level[current.row][current.column] = level[r][c]+1;
        Q.push(current);
    }
}

main(){
    int A[size] = {1, 2, 1, 1, 2};
    int B[size] = {3, 1, 2, 1, 2};
    int C[size] = {2, 1, 1, 1, 1};
    int D[size] = {2, 1, 1, 2, 2};
    int E[size] = {3, 1, 3, 2, 1};

    int *puzzle[size] = {A, B, C, D, E};
    PuzzleBoard PB(size, puzzle);
    cout << PB;
    cout << PB.solve() << endl;
}
