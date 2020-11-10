#include <stdio.h>
#include <stdbool.h>
bool ood(unsigned char data){
    int mask = 1;
    if(data&mask==0){
        return false;
    }
    else{
        return true;
    }
}
int main(){
   unsigned char one = '4';
  // int a = ood(one);
   printf("%d", ood(one));
}
