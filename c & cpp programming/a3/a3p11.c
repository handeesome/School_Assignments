/*
CH-230-B
a3 p11.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
#include <string.h>
int main(){
    char one[100], two[100];
    scanf("%[^\n]", one);
    getchar();
    scanf("%[^\n]", two);
    getchar();
    char c;
    scanf("%c", &c);

    printf("length1=%zu\n", strlen(one));
    printf("length2=%zu\n", strlen(two));

    char concatenation[100];
    strcpy(concatenation, one);
    strcat(concatenation, two);
    printf("concatenation=%s\n", concatenation);

    char three[100];
    strcpy(three, two);
    printf("copy=%s\n", three);

    if (strcmp(one, two)<0){
        printf("one is smaller than two\n");
    }
    else if(strcmp(one,two)>0){
        printf("one is larger than two\n");
    }
    else if(strcmp(one, two)==0){
        printf("one is equal to two\n");
    }


    for (int i=0; i<strlen(two); i++){
        if (c==two[i]){
        printf("position=%d\n", i);
        break;
        }
        else if (i==strlen(two)-1){
            printf("The character is not in the string\n");

        }
    }
    return 0;
}

