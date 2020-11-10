/*
CH-230-B
a7 p7.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include "stack.h"
int main(){
    my_stack = (struct stack*)calloc(12, sizeof(struct stack));
    my_stack ->count = -1;

    char c;
    int num;
    while(1){
        scanf("%c", &c);
        switch (c){
            case 's':
                scanf("%d", &num);
                if(isfull()==0){
                    printf("Pushing %d\n", num);
                }
                push(num);
                break;
            case 'p':
                if(isempty()==0){
                    printf("Popping %d\n", pop());
                }
                else{
                    pop();
                }
                break;
            case 'e':
                empty();
                break;
            case 'q':
                printf("Quit\n");
                exit(0);
        }
    }
}

