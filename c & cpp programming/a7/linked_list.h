 /*
CH-230-B
a7 p3.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>

struct list {
    int info ;
    struct list * next;
}*my_list;
void print_list ( struct list * my_list );
struct list *addtoend(int num, struct list *my_list);
struct list *addtobeginning(int num,  struct list *my_list);
struct list *remove_first( struct list *my_list);
void free_list(struct list *my_list);
