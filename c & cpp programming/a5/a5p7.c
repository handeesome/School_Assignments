/*
CH-230-B
a5 p7.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
//two strings with size of 100
//two strings with exact size
    char str1[100], str2[100], *newstr1, *newstr2;
    fgets(str1, sizeof(str1), stdin);
//get rid of the '\n' at the end of strings
    if (str1[strlen(str1)-1]=='\n'){
        str1[strlen(str1)-1]=0;
    }
    fgets(str2, sizeof(str2), stdin);
    if (str2[strlen(str2)-1]=='\n'){
        str2[strlen(str2)-1]=0;
    }
//allocate the size of newstr1 as length of str1 + str2
//because newstr1 is going to be the concatenation of the two
    newstr1 = (char*)malloc(sizeof(char)*(strlen(str1)+strlen(str2)));
    if (newstr1==NULL){
        exit (1);
    }
    newstr2 = (char*)malloc(sizeof(char)*strlen(str2));
    if (newstr2==NULL){
        exit(1);
    }
//make newstr1 and newtr2 exact size by copying
    strcpy(newstr1, str1);
    strcpy(newstr2, str2);
//put them together

    strcat(newstr1, newstr2);
    printf("Result of concatenation: %s\n", newstr1);

    free(newstr1);
    free(newstr2);
    return 0;
}
