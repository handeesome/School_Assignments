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

    printf("length1=%d\n", strlen(one));
    printf("length2=%d\n", strlen(two));

    char concatenation[100];
    strcpy(concatenation, one);
    strcat(concatenation, two);
    printf("concatenation=%s\n", concatenation);

    char three[100];
    strcpy(three, two);
    printf("copy=%s\n", three);

    if (strlen(one)<strlen(two)){
        printf("one is smaller than two");
    }
    else{
        printf("two is smaller than one\n");
    }


    for (int i=0; i<strlen(two); i++){
        if (c==two[i]){
        printf("position=%d\n", i);
        break;
        }
    }
}

