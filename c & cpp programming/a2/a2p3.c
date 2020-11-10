/*
CH-230-B
a2 p3.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
int main (){
    int a, b, c;
    printf("weeks: ");
    scanf("%d", &a);
    printf("days: ");
    scanf("%d", &b);
    printf("hours: ");
    scanf("%d", &c);
    int totalhours= a*24*7 + b*24 + c; // the total hours computed
    printf("total numbers of hours: %d", totalhours);

    return 0;
}
