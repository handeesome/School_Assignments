/*
CH-230-B
a6 p7.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
#include <math.h>
int set3bits(unsigned char unsign, int x, int y, int z){
    int mask = 128;
    int sum=0;
    int power=7;
    while (mask>0){
        int binary = (unsign & mask)/mask;
        if (power==x){
            sum = sum + 1*pow(10, power);
        }
        else if (power==y){
            sum = sum + 1*pow(10, power);
        }
        else if (power==z){
            sum = sum + 1*pow(10, power);
        }
        else if (binary==0){

        }
        else{
            sum = sum + binary*pow(10, power);
        }
        mask = mask/2;
        power--;
    }
    return sum;
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
    printf("After setting the bits: %d\n", set3bits(unsign, x, y, z));
    return 0;
}
