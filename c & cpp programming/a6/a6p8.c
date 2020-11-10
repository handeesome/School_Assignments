 /*
CH-230-B
a6 p8.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
// struct a singly linked list type and declare my_list
struct list {
    int info ;
    struct list * next;
}*my_list;
//start from first address of the pointer
//print every info and turn to next address
void print_list ( struct list * my_list ) {
    struct list * p ;
    p = my_list;
    for ( p = my_list ; p ; p = p -> next ) {
    printf ("%d ", p -> info ) ;
    }
    printf("\n");
}
//store new value into temp
//switch pointer of p every loop instead of the globe list my_list
//add a new element to the end of the list by moving the pointer
//to the end till NULL and add an element
struct list *addtoend(int num, struct list *my_list){
    struct list *temp = (struct list*)malloc(sizeof(struct list));
    temp->info = num;
    temp->next = NULL;
    struct list *p;
    p = my_list;
    if (p==NULL){
        my_list = temp;
        }
    else{
        while (p->next!=NULL){
        p = p->next;
        }
        p->next = temp;
    }
    return my_list;
}
//add a new element to the beginning of the list by
//new element pointing to the old list and my_list
//pointing to new element which makes a new list
struct list *addtobeginning(int num,  struct list *my_list){
    struct list *temp = (struct list*)malloc(sizeof(struct list));
    temp->info = num;
    temp->next = NULL;
    if (my_list==NULL){
        my_list = temp;
    }
    else{
        temp->next = my_list;
        my_list = temp;
    }
    return my_list;
}
//remove the first element of the list by
//point to the next element
struct list *remove_first( struct list *my_list){
    struct list *temp = (struct list*)malloc(sizeof(struct list));
    temp = my_list;
    if (temp==NULL){
        temp = NULL;
    }
    else {
        my_list = temp->next;
    }
    return my_list;
}
//free the list in the order of from the first element
void free_list(struct list *my_list){
    struct list *lastelement;
    while (my_list!=NULL){
        lastelement = my_list->next;
        free(my_list);
        my_list = lastelement;
    }
}
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
