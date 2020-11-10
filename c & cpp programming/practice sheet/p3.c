#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    scanf("%d", &n);
    int num = (int*)malloc(sizeof(int)*n);
    for (int i=0; i<n; i++){
        scanf("%d", &num[i]);
    }
    FILE *a = fopen("squares.txt", "w");
    for (int i=n-1; i>-1; i--){
        fprintf(a, "%d %d\n", num[i], num[i]*num[i]);
    }
}
