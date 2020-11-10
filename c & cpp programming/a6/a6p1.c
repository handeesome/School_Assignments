/*
CH-230-B
a6 p1.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
//SWAP function swaps two variables
//by using a temp value of an unsigned type
#define SWAP(x, y, type) {type t=x; x=y; y=t;}
int main(){
    int v1, v2;
    double v3, v4;
    scanf("%d\n%d", &v1, &v2);
    scanf("%lf\n%lf", &v3, &v4);
//the type of data is assigned at the last argument
    SWAP(v1, v2, int);
    SWAP(v3, v4, double);
    printf("After swapping:\n%d\n%d\n", v1, v2);
    printf("%lf\n%lf\n", v3, v4);

    return 0;
}
