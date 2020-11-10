/*
CH-230-B
a4 p12.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
#include <string.h>
void replaceAll(char *str, char c, char e){
//replacing all "c" with "e"
    for (int i=0; i<strlen(str); i++){
        if (c==str[i]){
            str[i]=e;
        }
    }
}
int main(){
    char str[80];
    char c, e;
    while (1==1){
//repeatedly read a string from keyboard
//if "stop" is entered, break
        printf("Please enter a string: ");
        fgets(str, sizeof(str), stdin);
        if (strcmp(str, "stop\n")==0){
            break;
        }
        printf("Enter what to be replaced: ");
        scanf("%c", &c);
        getchar();
        printf("Enter replace with: ");
        scanf("%c", &e);
        getchar();
        replaceAll(str, c, e);
        printf("String after replacement: %s", str);
    }
    return 0;
}
