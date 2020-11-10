 /*
CH-230-B
a7 p3.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include "linked_list.h"

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
