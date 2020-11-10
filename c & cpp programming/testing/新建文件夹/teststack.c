/*
CH-230-B
a7 p7.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include "stack.h"
#include "stack.c"
int main(){
    push(1);
    printf("1");
    struct stack *my_stack = (struct stack*)calloc(12, sizeof(struct stack));
    my_stack ->count = -1;

    unsigned int num;
    scanf("%u", &num);
    int division = num, remainder;

    while(division!=0){

        division = division/2;
        remainder = division%2;
        push(remainder);
    }
    printf("The binary representation of &d is ", num);
    prints(my_stack);
}

