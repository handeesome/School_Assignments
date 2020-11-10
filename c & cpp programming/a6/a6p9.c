 /*
CH-230-B
a6 p9.[c]
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
    for ( p = my_list ; p ; p = p -> next ) {
    printf ("%d ", p -> info ) ;
    }
    printf("\n");
}
//every time a list can go next means there is a number
//so that the length of the list can be counted
int Length(struct list *my_list){
    struct list *p;
    int count=0;
    for (p = my_list; p; p = p->next){
        count++;
    }
    return count;
}
//store new value into temp
//switch pointer of p every loop instead of the globe list my_list
//add a new element to the end of the list by moving the pointer
//to the end till NULL and add an element
void addtoend(int num){
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
}
//add a new element to the beginning of the list by
//new element pointing to the old list and my_list
//pointing to new element which makes a new list
void addtobeginning(int num){
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
}
//remove the first element of the list by
//point to the next element
void remove_first(){
    struct list *temp = (struct list*)malloc(sizeof(struct list));
    temp = my_list;
    if (temp==NULL){
        temp = NULL;
    }
    else {
        my_list = temp->next;
    }
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
//create two pointers, one points to the new number, another
//go next for my_list since my_list is a global list
//check the position entered is within the length first
//then link new number with the right part of the segment
//before linking the left part
void insert(){

    struct list *newnum = (struct list*)malloc(sizeof(struct list));
    struct list *temp = (struct list*)malloc(sizeof(struct list));
    temp = my_list;
    int pos, num;
    scanf("%d", &pos);
    scanf("%d", &num);
    if (pos>Length(my_list)-1 || pos<0){
        printf("Invalid position!\n");
        scanf("%d", &pos);
    }
    else if(pos==0){
        addtobeginning(num);
    }
    else{
        newnum->info = num;
        newnum->next = NULL;
        for (int i=1; i<pos; i++){
            temp = temp->next;
        }
        newnum->next = temp->next;
        temp->next = newnum;
    }
}
//start from the last number of the list
//add it to the end of the list, until the first number of the list
//and then remove the original list
void Reverse(){
    int len = Length(my_list);
    struct list* p = (struct list *)malloc(sizeof(struct list));
    for (int i=0; i<len; len--){
        p = my_list;
        for (int j=1; j<len; j++){
            p = p->next;
        }
        addtoend(p->info);
    }
//this "i<Length(my_list)" saves making another int to store original len
//because I am so brilliant!
    for (int i=0; i<Length(my_list); i++){
        remove_first();
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
        case 'i':
            insert();
            break;
        case 'R':
            Reverse();
            break;
        }
    }
    return 0;
}
