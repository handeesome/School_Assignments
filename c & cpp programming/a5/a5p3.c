/*
CH-230-B
a5 p3.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
//this function counts the number of lowercased letters
//in a string
int count_lower(char* str){
    int count=0;
//because fgets always have a '\n' at the end, so strlen-1
    for (int i=0; i<strlen(str)-1; i++){
        if (islower(str[i])>0){
            count++;
        }
    }
    return count;
}
int main(){
    char str[50];
    while (1==1){
        printf("Please enter a string: ");
        fgets(str, 50, stdin);
//when the string only contain '\n', it stops
        if (str[0]=='\n'){
            break;
        }
        printf("The string has %d lowercased letters.\n", count_lower(str));
    }
    return 0;
}
