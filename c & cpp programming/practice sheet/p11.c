#include <stdio.h>
#include <stdlib.h>
struct node {
    char str[20];
    struct list* next;
};
struct list *insertBegin(struct node* a, char str[]){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->str = str;
    temp->next = NULL;

    temp->next = a;
    a = temp;
    return a;
}

void printList(struct node *a){
    struct node *temp;
    temp = a;
    for (temp = a; temp; temp = temp->next){
        printf("%s", temp->str);
    }
    printf("\n");
}
