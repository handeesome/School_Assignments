/*
CH-230-B
a3 p2.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
int main(){
    char ch;
    int n;
    scanf("%c", &ch);
    scanf("%d", &n);

    int i;
    for (i=1; i<=n;  i++){
        printf("%d\n", ch-i);
    }
    return 0;
}
