/*
b CH-230-B
a4 p4.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
#include <string.h>
int count_consonants(char str[]){
    int consonants=0;
    for (int i=0; i<strlen(str); i++){
        switch (str[i]){
        case 66 ... 68:
        case 70 ... 72:
        case 74 ... 78:
        case 80 ... 84:
        case 86 ... 90:
        case 98 ... 100:
        case 102 ... 104:
        case 106 ... 110:
        case 112 ... 116:
        case 118 ... 122:
            consonants++;
        break;
        }
    }
    return consonants;
}
int main(){
    char str[100];
    while(1==1){
    fgets(str, sizeof(str), stdin);
    if (str[0]=='\n'){
        break;
    }
    printf("Number of consonants=%d\n", count_consonants(str));
    }
    return 0;
}
