/*
CH-230-B
a2 p5.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
int main(){
    int a;
    printf("please put a variable a:");
    scanf("%d", &a);
    printf("%d\n", a); //printing a.
    int *ptr_a;
    ptr_a = &a; //put a into address of ptr_a.
    printf("address of a:%p\n", ptr_a);
    *ptr_a+=5;
    printf("modified value is:%d\n", *ptr_a);
    printf("address of *ptr_a is:%p\n", ptr_a);

    return 0;
}
