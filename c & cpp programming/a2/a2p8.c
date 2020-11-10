/*
CH-230-B
a2 p8.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
int main(){
    int a;
    scanf("%d", &a);

    if(a%2==0 && a%7==0){

       printf("The number is divisible by 2 and 7\n");
    }
    else{
       printf("The number is NOT divisible by 2 and 7\n");
    }

    return 0;
}
