/**
 * @file queue.c
 */

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

void initialize_queue(Queue *pq)
{
	pq->front = pq->rear = NULL;
	pq->items = 0;
}

int queue_is_full(const Queue *pq)
{
	return pq->items == MAXQUEUE;
}

int queue_is_empty(const Queue *pq)
{
	return pq->items == 0;
}

int queue_item_count(const Queue *pq)
{
	return pq->items;
}

int enqueue(Item item, Queue *pq)
{
	if(queue_is_full(pq)){
        return 0;
	}
	struct node *p = (struct node*)malloc(sizeof(struct node));
	p->item = item;
	p->next = NULL;
	if (queue_is_empty(pq)){
        pq->front = p;
	}
	else{
        pq->rear->next = p;
	}
    pq->rear = p;
    pq->items++;
        return 0;
}

int dequeue(Item *pitem, Queue *pq)
{
	if (queue_is_empty(pq)){
        return 0;
	}
	else{

        int n;
        n = pq->front->item;
        *pitem = n;

        Node *p;
        p = pq->front;
        pq->front = pq->front->next;
        free(p);

        if (queue_is_empty(pq)){
            pq->front = NULL;
            pq->rear = NULL;
        }
        pq->items--;
	}
        return *pitem;
}

void empty_queue(Queue *pq)
{
	Item dummy;
	while (!queue_is_empty(pq)) {
		dequeue(&dummy, pq);
	}
}

void printq(Queue *pq){
    Node *temp = pq->front;
    for (int i=0; i<(pq->items); i++){
        printf("%d ", temp->item);
        temp = temp->next;
    }
    printf("\n");
}
