/*
CH-230-B
a7 p3.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include "linked_list.h"

int main(){
    struct list *my_list;
    char c;
    my_list = (struct list *)malloc(sizeof(struct list));
    my_list = NULL;
    int num;
    while (1){
        scanf("%c", &c);
        switch(c){
        case 'a':
            scanf("%d", &num);
            my_list = addtoend(num, my_list);
            break;
        case 'b':
            scanf("%d", &num);
            my_list = addtobeginning(num, my_list);
            break;
        case 'r':
            my_list = remove_first(my_list);
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
