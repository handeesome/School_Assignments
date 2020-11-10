#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//stack which can store words in
struct stack {
unsigned int count;
char *array[30]; // Container
}*my_stack;

int isfull(struct stack *my_stack);

//push a word from keyboard into stack
void push(char *string, struct stack *my_stack);

int isempty(struct stack *my_stack);

//pop the last word from the stack
char *pop(struct stack *my_stack);

void empty(struct stack *my_stack);
