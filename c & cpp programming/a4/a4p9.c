/*
CH-230-B
a4 p9.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
int prodminmax (int arr[], int n){
//first make "max" and "min" arr[0]
//in case they are the max or min
    int max=arr[0], min=arr[0];
    for (int i=0; i<n; i++){
        if (max<arr[i]){
            max = arr[i];
        }
    }
    for (int i=0; i<n; i++){
        if (min>arr[i]){
            min = arr[i];
        }
    }
// return product
    int product = max * min;
    return product;
}
int main(){
    int n, *arr;
    printf("Please enter how many numbers in the array: ");
    scanf("%d", &n);
//malloc size since n is unknown
    arr = (int*) malloc(sizeof(int)*n);
    if (arr==NULL){
        exit (1);
    }
    for (int i=0; i<n; i++){
        printf("Number %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("The product of max and min is: %d", prodminmax(arr, n));
    free(arr);
    return 0;
}
