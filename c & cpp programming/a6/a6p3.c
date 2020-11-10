/*
CH-230-B
a6 p3.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
//find max between 3 numbers
//if a is greater than b and c, max is a
//if not, compare b and c only because a and b are already compared
#define MAX(a, b, c) ((a>b && a>c) ? a : (b>c) ? b : c)
//same idea of MAX
#define MIN(a, b, c) ((a<b && a<c) ? a : (b<c) ? b : c)
//change the data type of MAX and MIn to float so that it prints float
#define MIDRANGE(a, b, c) ((float)(MAX(a, b, c)+(float)MIN(a, b, c))/2)
int main(){
    int a, b, c;
    scanf("%d\n%d\n%d", &a, &b, &c);
    printf("The mid-range is: %f\n", MIDRANGE(a, b, c));

    return 0;
}
