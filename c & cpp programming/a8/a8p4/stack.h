
#include <stdio.h>
#include <stdlib.h>
//defining a type through struct and name it Stack
//it has a number in it with the current array number
struct stack {
    unsigned int count;
    int array[12]; // Container
}*my_stack;

//determines whether the queue is full
int isfull();

//push in an element at the top of the stack
void push(int element);

//determine whether the queue is empty
int isempty();

//pop out the element at the top of the stack
int pop();

//empty the stack by pop all the elements
void empty();

//prints the stack from the bottom
void prints();
