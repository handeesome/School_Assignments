/*
CH-230-B
a2 p6.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
int main(){
    double x, y;
    scanf("%lf", &x);
    scanf("%lf", &y);
    double *ptr_one, *ptr_two, *ptr_three;
    ptr_one= &x;
    ptr_two= &x;
    ptr_three= &y;
    printf("address of *ptr_one is:%p\n", ptr_one);
    printf("address of *ptr_two is:%p\n", ptr_two);
    printf("address of *ptr_three is:%p\n", ptr_three);

    return 0;

}
