/*
CH-230-B
a5 p4.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
//this function divides every element in the array by 5
void divby5(float arr[], int size){

    for (int i=0; i<size; i++){
        arr[i] = arr[i]/5;
    }

}
int main(){
    int n;
    printf("How many elements in the array: ");
    scanf("%d", &n);
    float *arr;
    arr = malloc(sizeof(float)*n);
    if (arr==NULL){
        exit (1);
    }
    for (int i=0; i<n; i++){
        printf("Number %d: ", i+1);
        scanf("%f", &arr[i]);
    }
//printing the elements in the array before division
    printf("Before:\n");
    for (int i=0; i<n; i++){
        printf("%.3f ", arr[i]);
        if (i==n-1){
            printf("\n");
        }
    }
//calling function divby5
    divby5(arr, n);
//printing the elements in the array after division
    printf("After:\n");
    for (int i=0; i<n; i++){
        printf("%.3f ", arr[i]);
        if (i==n-1){
            printf("\n");
        }
    }
    free(arr);
    return 0;
}
