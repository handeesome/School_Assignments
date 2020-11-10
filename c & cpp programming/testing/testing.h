#ifndef TESTING_H_INCLUDED
#define TESTING_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "Untitled2.c"
struct list;
void print_list ( struct list * my_list );
void addtoend(int num);
void addtobeginning(int num);
void remove_first();
void free_list(struct list *my_list);

#endif // TESTING_H_INCLUDED
