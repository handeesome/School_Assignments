/*
CH-230-B
a6 p7.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
#include <math.h>
void set3bits(unsigned char unsign, int x, int y, int z){
    int mask = 128;
    while (mask>0){
        int binary = (unsign & mask)/mask;
        if (mask == pow(2, x)){
            printf("1");
        }
        else if (mask == pow(2, y)){
            printf("1");
        }
        else if (mask == pow(2, z)){
            printf("1");
        }
        else{
        printf("%d", binary);
        }
        mask = mask/2;
    }
    printf("\n");
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
    printf("\n");
    printf("After setting the bits: ");
    set3bits(unsign, x, y, z);
    return 0;
}
