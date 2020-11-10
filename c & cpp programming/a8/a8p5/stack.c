#include "stack.h"
int isfull(struct stack *my_stack){
    if(my_stack->count == 11){
        return 1;
    }
    else{
        return 0;
    }
}
void push(char *string, struct stack *my_stack){
    if(isfull(my_stack)==1){
        printf("Pushing Stack Overflow\n");
    }
    else {
        my_stack->count++;
        my_stack->array[my_stack->count] = (char*)malloc(sizeof(char)*30);
        strcpy(my_stack->array[my_stack->count], string);
    }
}
int isempty(struct stack *my_stack){
    if(my_stack->count == -1){
        return 1;
    }
    else{
        return 0;
    }
}
char *pop(struct stack *my_stack){
    if (isempty(my_stack)==1){
        printf("Popping Stack Underflow\n");
        return '\0';
    }
    else{
        my_stack->array[my_stack->count] = NULL;
        my_stack->count--;
        return 0;
    }
}
void empty(struct stack *my_stack){
    while(isempty(my_stack)==0){
         pop(my_stack);
    }
}
