/*
CH-230-B
a8 p4.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include "stack.h"
int main(){
    my_stack = (struct stack*)calloc(12, sizeof(struct stack));
    my_stack ->count = -1;


    unsigned int num;
    scanf("%u", &num);
    int division = num;
    int remainder;

//using division by 2 and store the remainder into the stack
//and print out one by one when finished
    while(division!=0){

        remainder = division%2;
        division = division/2;
        push(remainder);
    }
    printf("The binary representation of %d is ", num);
    prints(my_stack);

    return 0;

}

