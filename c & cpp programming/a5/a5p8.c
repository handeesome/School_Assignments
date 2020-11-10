/*
CH-230-B
a5 p8.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
//this function read a matrix from the keyboard
void read(int **matrix, int row, int column){
    for (int r=0; r<row; r++){
        for (int c=0; c<column; c++){
            scanf("%d", &matrix[r][c]);
        }
    }
}
//this function print out a matrix
void print(int **matrix, int row, int column){
    for (int r=0; r<row; r++){
        for (int c=0; c<column; c++){
            printf("%d ", matrix[r][c]);
            if (c==column-1){
                printf("\n");
            }
        }
    }
}
//this function computes the multiplication of two matrices
void Multiplication(int **A, int **B, int **AB, int n, int m, int p){
    for (int rA=0; rA<n; rA++){
        for (int cA=0; cA<p; cA++){
            int sum=0;
            for (int rB=0; rB<m; rB++){
                sum = sum + A[rA][rB]*B[rB][cA];
            }
            AB[rA][cA] = sum;
        }
    }
}
int main(){
    int n, m, p;
//n is the row number of matrix A
//m is the column number of matrix A and row of B
//p is the column number of matrix B
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &p);
//pointer of pointers
    int **A = (int **)malloc(sizeof(int*)*n);
    if (A==NULL){
        exit(1);
    }
    int **B = (int **)malloc(sizeof(int*)*m);
    if (B==NULL){
        exit(1);
    }
    int **AB = (int **)malloc(sizeof(int*)*n);
    if (AB==NULL){
        exit(1);
    }
    for (int i=0; i<n; i++){
//pointer of int arrays
        A[i] = (int*)malloc(sizeof(int)*m);
        if (A[i]==NULL){
            exit(1);
        }
        AB[i] = (int*)malloc(sizeof(int)*p);
        if (AB[i]==NULL){
            exit(1);
        }
    }
    for (int i=0; i<m; i++){
        B[i] = (int*)malloc(sizeof(int)*p);
        if (B[i]==NULL){
            exit(1);
        }
    }
    read(A, n, m);
    read(B, m, p);
    printf("Matrix A:\n");
    print(A, n, m);
    printf("Matrix B:\n");
    print(B, m, p);
    printf("The multiplication result AxB:\n");
    Multiplication(A, B, AB, n, m, p);
    print(AB, n, p);

    for (int i=0; i<n; i++){
        free(A[i]);
        free(AB[i]);
    }
    for (int i=0; i<m; i++){
        free(B[i]);
    }
    free(A);
    free(B);
    free(AB);
    return 0;
}
