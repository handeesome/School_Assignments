/*
CH-230-B
a5 p10.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
//this function prints the numbers n, n-1, . . . , 1.
int recursive(int n){
    if (n==1){
        printf("%d.", n);
        return 0;
    }
    printf("%d, ", n);
    return recursive(n-1);
}
int main(){
    int n;
    printf("Please enter a positive integer: ");
    scanf("%d", &n);
    printf("All positive integers smaller than or equal to %d: \n", n);
//calling the recursive function
    recursive(n);

    return 0;
}
