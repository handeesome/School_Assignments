/*
CH-230-B
a4 p2.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
#include <string.h>
int main(){
    char string[50];
    fgets(string, sizeof(string), stdin);
    int i;
    for (i=0; i<strlen(string) && string[i]!= '\n'; i++){
        if (i%2==0){
            printf("%c\n", string[i]);
        }
        else{
            printf(" %c\n", string[i]);
        }
    }
    return 0;
}
