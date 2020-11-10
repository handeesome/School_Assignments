/*
CH-230-B
a7 p7.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include "stack.h"

struct stack {
unsigned int count;
int array[12]; // Container
}*my_stack;

int isfull(){
    if(my_stack->count == 11){
        return 1;
    }
    else{
        return 0;
    }
}
void push(int element){
    if(isfull()==1){
        printf("Pushing Stack Overflow\n");
    }
    else {
        my_stack->count++;
        my_stack->array[my_stack->count] = element;
    }
}
int isempty(){
    if(my_stack->count == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int pop(){
    int element;
    if (isempty()==1){
        printf("Popping Stack Underflow\n");
        return '\0';
    }
    else{
        element = my_stack->array[my_stack->count];
        my_stack->count--;
        return element;
    }
}
void empty(){
    printf("Emptying Stack ");
    while(isempty()==0){
        printf("%d ", pop());
    }
    printf("\n");
}
void prints(){
    while(isempty(my_stack)==0){
        printf("%d", pop(my_stack));
    }
    printf(".");
}

