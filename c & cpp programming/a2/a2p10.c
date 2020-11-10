/*
CH-230-B
a2 p10.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
int main(){
    int n;
    int d=1;
    scanf("%d", &n);

    while (n<1){
        scanf("%d", &n);
    }

    while(d<=n){
            if(d==1){
                printf("1 day = 24 hours\n");
                d++;
                while(d<=n){
                        printf("%d days = %d hours\n", d, d*24);
        d++;
                        }
                }
    return 0;
            }
}
