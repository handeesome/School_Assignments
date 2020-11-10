/*
CH-230-B
a7 p5.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
//function needed by qsort
int cmpar (const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}
//print the sorted array ascending
void ascending(int* array, int n){
    for (int i=0; i<n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}
//print the sorted array descending
void descending(int* array, int n){
    for (int i=n-1; i>=0; i--){
        printf("%d ", array[i]);
    }
    printf("\n");
}
//put elements into the array, and then
//create a function pointer and
//uses that and qsort to sort the array
int main(){
    int n;
    scanf("%d", &n);
    int *array = (int*)malloc(sizeof(int)*n);
    for (int i=0; i<n; i++){
        scanf("%d", &array[i]);
    }

    int (*p)(const void *, const void *);
    p = cmpar;
    qsort(array, n, sizeof(int), p);

    char c;
    while(1){
        scanf("%c", &c);
        switch(c){
        case 'a':
            ascending(array, n);
            break;
        case 'd':
            descending(array, n);
            break;
        case 'e':
            exit(0);
        }
    }
    return 0;
}
