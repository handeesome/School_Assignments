/*
CH-230-B
a5 p6.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    float *arr;
    scanf("%d", &n);
    arr = (float *)malloc(sizeof(float)*n);
    if (arr==NULL){
        exit(1);
    }
    for (int i=0; i<n; i++){
        scanf("%f", &arr[i]);
    }
//when a negative number occurs, counts
//how many elements before that number
//using pointer arithmetic
    for (int i=0; i<n; i++){
        if (*(arr+i)<0){
        printf("Before the first negative value: %d elements\n", i);
        }
    }
    free(arr);
    return 0;
}
