/*
CH-230-B
a5 p1.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
void print(int n, char ch){
    for (int i=n; i>0; i--, n--){
        for (int t=0; t<n; t++){
            printf("%c", ch);
        if (t==n-1){
            printf("\n");
            }
        }
    }
}
int main(){
    int n;
    char ch;
    scanf("%d", &n);
    getchar();
    scanf("%c", &ch);
    print(n, ch);

    return 0;
}
