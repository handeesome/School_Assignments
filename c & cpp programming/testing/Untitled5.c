#include <stdio.h>
struct stack {
unsigned int count;
char *array[30]; // Container
}*my_stack;

int main(){
    my_stack = (struct stack*)calloc(12, sizeof(struct stack));
    my_stack ->count = -1;

       /* my_stack->array[0] = (char*)malloc(sizeof(char)*30);
        my_stack->array[1] = (char*)malloc(sizeof(char)*30);
        my_stack->array[2] = (char*)malloc(sizeof(char)*30);
        my_stack->array[3] = (char*)malloc(sizeof(char)*30);
        my_stack->array[4] = (char*)malloc(sizeof(char)*30);
        my_stack->array[5] = (char*)malloc(sizeof(char)*30);*/

        for (int i=0; i<6; i++){
            my_stack->count++;
            my_stack->array[my_stack->count] = (char*)malloc(sizeof(char)*30);
            strcpy(my_stack->array[i], "hello");
            printf("%s ", my_stack->array[i]);
        }

   /* char *s[30];
    s[1] = (char*)malloc(sizeof(char)*30);
    s[2] = (char*)malloc(sizeof(char)*30);
    s[3] = (char*)malloc(sizeof(char)*30);
    scanf("%s", s[1]);
    scanf("%s", s[2]);
    scanf("%s", s[3]);
    printf("%s", s[1]);*/
}
