/*
CH-230-B
a8 p5.[c]
Cenhan Du
cdu@jacobs-university.de
*/

#include "stack.h"
//this program can only be used when the entered string has 12 words long
int main(){
    my_stack = (struct stack*)calloc(12, sizeof(struct stack));
    my_stack ->count = -1;

    char s[30];

    while(1){
        for (int i=0; i<12; i++){
            scanf("%s", s);
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
