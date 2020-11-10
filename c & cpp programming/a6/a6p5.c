/*
CH-230-B
a6 p5.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
int main(){
    int mask = 1;
    unsigned int unsign;
    scanf("%d", &unsign);
    printf("The decimal representation is: %d\n", unsign);
    printf("The backwards binary representation is: ");
    while (unsign>0){
//print every bit from the back without a new line
// &1 takes out the last bit
    //    int binary = unsign & mask;
        printf("%d", unsign&mask);
//after every loop, shift 1 to the right so new bit
        unsign = unsign>>1;
    }
    printf("\n");
    return 0;
}
