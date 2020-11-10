/*
CH-230-B
a5 p9.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
//read from r0c0d0 r0c0d1 and so on
void read(int*** array, int row, int column, int depth){
    for (int r=0; r<row; r++){
        for (int c=0; c<column; c++){
            for (int d=0; d<depth; d++){
                scanf("%d", &array[r][c][d]);
            }
        }
    }
}
//print the array by showing each element on one every depth
void print(int*** array, int row, int column, int depth){
     for (int d=0; d<depth; d++){
        printf("Section %d:\n", d+1);
        for (int r=0; r<row; r++){
            for (int c=0; c<column; c++){
                printf("%d ", array[r][c][d]);
                if (c==column-1){
                    printf("\n");
                }
            }
        }
    }
}
int main(){
    int x, y, z;
    scanf("%d\n%d\n%d", &x, &y, &z);
//allocate rows first then column at last depth
    int ***array = (int***)malloc(sizeof(int**)*x);
    if (array==NULL){
        exit(1);
    }
    for (int r=0; r<x; r++){
        array[r] = (int**)malloc(sizeof(int*)*y);
        if (array[r]==NULL){
            exit(1);
        }
    }
    for (int r=0; r<x; r++){
        for (int c=0; c<y; c++){
            array[r][c] = (int*)malloc(sizeof(int)*z);
            if (array[r][c]==NULL){
                exit(1);
            }
        }
    }
//calling functions to read and print
    read(array, x, y, z);
    print(array, x, y, z);
//deallocation of the memory
    for (int r=0; r<x; r++){
        for (int c=0; c<y; c++){
            free(array[r][c]);
        }
        free(array[r]);
    }
    free(array);

    return 0;
}
