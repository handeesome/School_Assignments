/*
CH-230-B
a4 p5.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
#include <string.h>
int count_consonants(char str[]){
//make consonant 0 first and count when meet
    int consonants=0;
//declaring a pointer p, pointing to
//the address of str[0], which makes
//it the string "str"
    char *p = &str[0];
    for (int i=0; i<strlen(str); i++){
//using address arithmetic here
        switch (*(p+i)){
//these are ASCII numbers of all consonants
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
//keep reading str until an empty string
    while(1==1){
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    if (str[0]=='\n'){
        break;
    }
    printf("Number of consonants=%d\n", count_consonants(str));
    }
    return 0;
}
