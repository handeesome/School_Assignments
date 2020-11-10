/*
CH-230-B
a4 p6.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
int greatest(int arr[], int size){
//make every value arr[0], in case it is the greatest number
    int greatest=arr[0], second=arr[0], first=arr[0];
    for (int i=0; i<size; i++){
//put a bigger number into "second" before put it into "first"
        if (second<arr[i]){
            second = arr[i];
        }
        if (first<second){
//make greatest as a temp for first
//because when "first= second"
//the value in "first" is gone
            greatest = first;
            first = second;
            second = greatest;
        }
    }
    printf("The greatest number is %d\nThe second greatest number is %d", first, second);
    return 0;
}
int main(){
    int *arr, n;
    printf("Please enter how many numbers in the array: ");
    scanf("%d", &n);
//because array "arr" has no size
//malloc it, and check if its valid
    arr = (int*) malloc(sizeof (int) * n);
    if ( arr == NULL ){
    exit (1) ;
    }
    for (int i=0; i<n; i++){
        printf("Number %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    greatest(arr, n);
    free (arr);

    return 0;
}
