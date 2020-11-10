/*
CH-230-B
a7 p7.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack {
unsigned int count;
char *array[30]; // Container
}*my_stack;
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
    char s[30];
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


int main(){
    my_stack = (struct stack*)calloc(12, sizeof(struct stack));
    my_stack ->count = -1;

    char s[30];

    while(1){
        for (int i=0; i<12; i++){
            scanf("%s", s);
            if (s=="\n"){
                break;
            }
            push(s, my_stack);
        }
        for (int i=0, j=11; i<6; i++, j--){
            if(strcmp(my_stack->array[i], my_stack->array[j])==0){

            }
            else{
                printf("The sentence is not palindromic by words!\n");
                break;
            }
            if(i==5){
                printf("The sentence is palindromic by words!\n");
            }
        }
        empty(my_stack);
    }





    return 0;

}
