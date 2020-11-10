/*
CH-230-B
a6 p7.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
#include <math.h>
//move 1 every x, y, or z times to the left and OR them so that the
//positions of these are 1 no matter they use to be
unsigned char set3bits(unsigned char unsign, int x, int y, int z){
    unsign = unsign | (1<<x) | (1<<y) | (1<<z);
    return unsign;
    }
int main(){
    unsigned char unsign;
    scanf("%c", &unsign);
    int x, y, z;
    scanf("%d\n%d\n%d", &x, &y, &z);
    printf("The decimal representation is: %d\n", unsign);
    printf("The binary representation is: ");
    int mask = 128;
    while (mask>0){
        int binary = (unsign & mask)/mask;
        printf("%d", binary);
        mask = mask/2;
    }
    printf("\nAfter setting the bits: ");
    mask = 128;
    while (mask>0){
//print the new binary after the replacement of 3 bits
        int binary = (set3bits(unsign, x, y, z) & mask)/mask;
        printf("%d", binary);
        mask = mask/2;
    }
    printf("\n");
    return 0;
}
