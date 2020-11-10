#include <stdio.h>
int main(){
    int mask = 1;
    int res = 0;
    int number = 50;
    while(number>0){
        res=res<<1;
        res = res|(number & mask);
        number=number>>1;
        printf("%d\n", res);
    }
    //printf("%d", res);
}
