/*
CH-230-B
a4 p11.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int count_insensitive(char *str, char c){
    int count=0;
//if the entered "c" is a lowercase
//make every letter lowercase first
//and then count
    if(c>97 && c<122){
        for (int i=0; i<strlen(str); i++){
            str[i] = tolower(str[i]);
            if (c==str[i]){
                count++;
            }
        }
    }
//same like the lowercase, but for a capital one
    else if(c>65 && c<90){
        for (int i=0; i<strlen(str); i++){
            str[i] = toupper(str[i]);
            if (c==str[i]){
                count++;
            }
        }
    }
    return count;
}
int main(){
    char *str1, *str2;
    char c;
    str1 = (char *) malloc (sizeof(char)*50);
    if ( str1 == NULL ){
        exit (1);
    }

    printf("Enter the string: ");
    fgets(str1, 50, stdin);
    printf("Character to count: ");
    scanf("%c", &c);

    str2 = (char*) malloc (sizeof(char)*sizeof(str1));
    if (str2 == NULL){
        exit (1);
    }
//copy str1 into str2 so that str2 has the exactly memory
    strcpy(str2, str1);
    printf("The character '%c' occurs %d times.", c, count_insensitive(str2, c));

    free (str1);
    return 0;
}
