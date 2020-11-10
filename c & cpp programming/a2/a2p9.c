/*
CH-230-B
a2 p9.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
int main(){
    char a;
    scanf("%c", &a);

    if(48<=a && a<=59){
        printf("%c is a digit\n", a);
    }
    else if(65<=a && a<=90){
        printf("%c is a letter\n", a);
    }
    else if(97<=a && a<=122){
        printf("%c is a letter\n", a);
    }
    else{
        printf("%c is some other symbol\n", a);
    }
    return 0;
}
