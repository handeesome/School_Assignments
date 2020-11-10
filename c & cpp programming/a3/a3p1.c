/*
CH-230-B
a3 p1.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
int main(){
    float x;
    scanf("%f", &x);
    int n;
    scanf("%d", &n);

    while (n<1){
        printf("Input is invalid, reenter value\n");
        scanf("%d", &n);
    }

    int i;
    for (i=0; i<n; i++){
        printf("%f\n", x);
    }
    return 0;
}
