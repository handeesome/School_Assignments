#include <stdio.h>
int main(){
    int n;
    char ch;
    scanf("%d", &n);
    getchar();
    scanf("%c", &ch);
    for (int i=0; i<n; i++){
        for(int j=i+1; j>0; j--){
            printf("%c", ch);
        }
        printf("\n");
    }
}
