/*
CH-230-B
a6 p4.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
//a macro that calculate intermediate product value
#define INTERMEDIATE(x, y) (x*y)
int main(){
    int dimension;
    printf("Dimension of the vectors: ");
    scanf("%d", &dimension);

    int* x = (int*)malloc(sizeof(int)*dimension);
    if (x==NULL){
        exit(1);
    }
    int* y = (int*)malloc(sizeof(int)*dimension);
    if (y==NULL){
        exit(1);
    }

    for (int i=0; i<dimension; i++){
        printf("Number %d of vector x: ", i+1);
        scanf("%d", &x[i]);
    }
    for (int i=0; i<dimension; i++){
        printf("Number %d of vector y: ", i+1);
        scanf("%d", &y[i]);
    }

    int SP = 0;
    for (int i=0; i<dimension; i++){
        SP = SP + x[i]*y[i];
    }
//if INTERMEDIATE is defined, print both intermediate
//and scalar products
    #ifdef INTERMEDIATE
        printf("The intermediate product values are:\n");
        for (int i=0; i<dimension; i++){
            printf("%d\n", INTERMEDIATE(x[i], y[i]));
        }
        printf("The scalar product is: %d", SP);
    #endif // INTERMEDIATE
//if INTERMEDIATE is not defined, print only scalar product
    #ifndef INTERMEDIATE
        printf("The scalar product is: %d", SP);
    #endif // INTERMEDIATE

    free(x);
    free(y);
    return 0;
}
