/*
CH-230-B
a7 p2.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
//create a double_linked_list, which can go back and forth
struct doublelist{
    char data;
    struct doublelist *last;
    struct doublelist *next;
}*my_list;
//add a node to the beginning of the list by
//linking "temp->next" to the original list and
void add_to_beginning(char character){
    struct doublelist *temp;
    temp = (struct doublelist*)malloc(sizeof(struct doublelist));
    temp ->data = character;
    temp ->last = NULL;
    temp ->next = NULL;
    if (my_list == NULL){
        my_list = temp;
    }
    else {
        temp -> next = my_list;
        my_list -> last = temp;
        my_list = temp;
    }
}
//link the previous and the next nodes and
//deallocate the node contains the character
void remove_character(char character){
    int count=0;
    struct doublelist *temp;
    struct doublelist *p;
    temp = my_list;
    p = my_list;

    while(temp!=NULL){
        if (temp->data == character){
            p = p->next;
            if (temp->last==NULL){
                free(p->last);
                p->last = NULL;
                my_list = p;
                temp = p;
                count++;
                continue;
            }
            p->last = temp->last;
            temp->last->next = p;
            free(temp);
            temp = p;
            count++;
            continue;
        }
        temp = temp->next;
        p = p->next;
    }
    if(count==0){
        printf("The element is not in the list!\n");
    }
}
//print from the beginning of the list in a loop
//after every loop the pointer shifts to next node
void printforwards(struct doublelist *my_list){
    struct doublelist *temp;
    temp = my_list;
    while(temp!=NULL){
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
//print from the end of the list in a loop
//after every loop the pointer shifts to the last node
void printbackwards(struct doublelist *my_list){
    struct doublelist *temp;
    temp = my_list;
    while (temp->next!=NULL){
        temp = temp->next;
    }
    while (temp!=NULL){
        printf("%c ", temp->data);
        temp = temp->last;
    }
    printf("\n");
}
//deallocate nodes one by one
//after deallocating one node, shift pointer to the next node
void free_list(struct doublelist *my_list){
    struct doublelist *lastelement;
    while (my_list!=NULL){
        lastelement = my_list->next;
        free(my_list);
        my_list = lastelement;
    }
}
int main(){
    my_list = (struct doublelist*)malloc(sizeof(struct doublelist));
    my_list = NULL;
    int num;
    char c;
    while(1){
        scanf("%d", &num);
        switch (num){
        case 1:
            getchar();
            scanf("%c", &c);
            add_to_beginning(c);
            break;
        case 2:
            getchar();
            scanf("%c", &c);
            remove_character(c);
            break;
        case 3:
            printforwards(my_list);
            break;
        case 4:
            printbackwards(my_list);
            break;
        case 5:
            free_list(my_list);
            exit(0);
            break;
        }
    }
    return 0;
}
