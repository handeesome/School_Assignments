#include <stdio.h>
#include <stdlib.h>
struct stack {
unsigned int count;
char *array[30]; // Container
}*my_stack;

int main(){
    my_stack = (struct stack*)calloc(12, sizeof(struct stack));
    my_stack ->count = -1;

    char s[30];
    int i=0;
    while(i<12){
        scanf("%s", s);
        my_stack->count++;
   //     printf("%d", my_stack->count);
     //   my_stack->array[my_stack->count] = "";
      //  strcpy(my_stack->array[my_stack->count], s);
        my_stack->array[my_stack->count] = (char*)malloc(sizeof(char)*30);
        strcpy(my_stack->array[my_stack->count], s);
     /*   my_stack->array[0] = "hello";
        my_stack->array[1] = "world";
        my_stack->array[2] = "stupid";
        my_stack->array[3] = "language";
        my_stack->array[4] = "yea";
        my_stack->array[5] = "you"; */
        printf("%s\n", my_stack->array[my_stack->count]);
        i++;
    }
    printf("%s ", my_stack->array[0]);
       /*
        printf("%s ", my_stack->array[1]);
        printf("%s ", my_stack->array[2]);
        printf("%s ", my_stack->array[3]);
        printf("%s ", my_stack->array[4]);
        printf("%s ", my_stack->array[5]);*/


}
