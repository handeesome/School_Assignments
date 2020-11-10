/*
CH-230-B
a5 p2.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
void divby5(float arr[], int size){
    printf("Before:\n");
    for (int i=0; i<size; i++){
        printf("%.3f ", arr[i]);
        if (i==size-1){
            printf("\n");
        }
    }
    printf("After:\n");
    for (int i=0; i<size; i++){
        arr[i] = arr[i]/5;
        printf("%.3f ", arr[i]);
        if (i==size-1){
            printf("\n");
        }
    }
}
int main(){
    int n=6;
    float arr[6] = {5.5, 6.5, 7.75, 8.0, 9.6, 10.36};
    divby5(arr, n);
    return 0;
}
