/*
CH-230-B
a7 p4.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void uppercase(char *string){
    char temp[110];
    strcpy(temp, string);
    for (int i=0; i<strlen(temp); i++){
        temp[i] = toupper(temp[i]);
    }
    printf("%s", temp);
}

void lowercase(char *string){
    char temp[110];
    strcpy(temp, string);
    for (int i=0; i<strlen(temp); i++){
        temp[i] = tolower(temp[i]);
    }
    printf("%s", temp);
}

void SwitchUpNLow(char *string){
    char temp[110];
    strcpy(temp, string);
    for (int i=0; i<strlen(temp); i++){
        while(islower(temp[i])==0){
            temp[i] = tolower(temp[i]);
            i++;
        }
        while(isupper(temp[i])==0){
            temp[i] = toupper(temp[i]);
        }
    }
    printf("%s", temp);
}

void quit(char *string){
    exit(0);
}

int main(){
    char string[110];
    fgets(string, 110, stdin);

    void (*array[4])(char*);
    array[0] = uppercase;
    array[1] = lowercase;
    array[2] = SwitchUpNLow;
    array[3] = quit;

    char c;
    while(1){
        scanf("%c", &c);
        getchar();
        (*array[(int)c-49])(string);
    }
    return 0;
}
