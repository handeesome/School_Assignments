/*
CH-230-B
a4 p13.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
void uppcase(char *str){
    for (int i=0; i<strlen(str); i++){
        if (isupper(str[i])==0){
            str[i] = toupper(str[i]);
        }
    }
    printf("%s", str);
}
void lowcase(char *str){
    for (int i=0; i<strlen(str); i++){
        if (islower(str[i])==0){
            str[i] = tolower(str[i]);
        }
    }
    printf("%s", str);
}

int main(){
    char str[90];
    while (1==1){
        fgets(str, sizeof(str), stdin);
        if (strcmp(str, "exit\n")==0){
            break;
        }
        printf("uppcase=");
        uppcase(str);
        printf("lowcase=");
        lowcase(str);
    }
    return 0;
}
