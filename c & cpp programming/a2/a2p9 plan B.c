#include <stdio.h>
int main(){

    char a;
    scanf("%c", &a);

    switch(a){
        case 48 ... 59:
            printf("%c is a digit\n", a);
            break;
        case 65 ... 90:
        case 97 ... 122:
            printf("%c is a letter\n", a);
            break;
        default:
            printf("%c is some other symbol\n", a);
            break;
    }

    return 0;
}
