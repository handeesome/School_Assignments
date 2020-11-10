 /*
CH-230-B
a7 p1.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#include "testing.h"
// struct a singly linked list type and declare my_list

int main(){
    char c;
    my_list = (struct list *)malloc(sizeof(struct list));
    my_list = NULL;
    int num;
    while (1){
        scanf("%c", &c);
        switch(c){
        case 'a':
            scanf("%d", &num);
            addtoend(num);
            break;
        case 'b':
            scanf("%d", &num);
            addtobeginning(num);
            break;
        case 'r':
            remove_first();
            break;
        case 'p':
            print_list(my_list);
            break;
        case 'q':
            free_list(my_list);
            exit(0);
            break;
        }
    }
    return 0;
}

