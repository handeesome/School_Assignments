/*
CH-230-B
a6 p2.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
//bitwise AND c with 00000001
//which compares 1 with the LSB of c
//if LAB of c is 1, it is 1, otherwise it's 0
#define LEASTBIT(c) (c&1)
int main(){
    char c;
    scanf("%c", &c);
    printf("The decimal representation is: %d\n", c);
    printf("The least significant bit is: %d", LEASTBIT(c));

    return 0;
}
