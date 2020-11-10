/*
CH-230-B
a6 p6.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
int main(){
    unsigned char unsign;
    printf("Enter an char: ");
    scanf("%c", &unsign);
//128=10000000 and after every loop, it gets rid of a 0
//by dividing 2 because 64=1000000 and 32=100000
    int mask = 128;
    printf("The decimal representation is: %d\n", unsign);
    printf("The binary representation is: ");
    while (mask>0){
//&mask with the number gives either 1 or 0, which is
//actually 1000000 sort of thing in binary
//so divide by an exactly same digit mask
//that makes it real 1 or 0
        int binary = (unsign & mask)/mask;
        printf("%d", binary);
//as mentioned before, divide by to gets rid of 0
        mask = mask/2;
    }
    printf("\n");
    return 0;
}
