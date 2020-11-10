#include <stdio.h>
void print_matrix(int **A, int rows, int cols){
    for (int r=0; r<rows; r++){
        for(int c=0; c<cols; c++){
            printf("%d ", A[r][c]);
        }
        printf("\n");
    }
}
int main(){
    FILE *a = fopen("matrix.txt", "r");
    int row, column;
    fscanf(a, "%d", &row);
    fscanf(a, "%d", &column);
    int tempr, tempc, tempv;
    fscanf(a, "%d %d %d", &tempr, &tempc, &tempv);
    printf("%d, %d, %d", tempr, tempc, tempv);
}
