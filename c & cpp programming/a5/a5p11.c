/*
CH-230-B
a5 p11.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
//this function detects if a positive integer is a prime or not
//by dividing increment of 2 until half of the integer
//prime return 0, else return 1
int detect_prime(int divide, int x){
    if (x==2){
        return 1;
    }
    else if (x%divide==0 ||x==1){
        return 0;
    }
    else if (divide==x/2 || x==3){
        return 1;
    }
    else{
        return detect_prime(divide+1, x);
    }
}
int main(){
    int x;
    scanf("%d", &x);
    if (detect_prime(2, x)==0){
        printf("%d is not prime\n", x);
    }
    else if (detect_prime(2, x)==1){
        printf("%d is prime\n", x);
    }

    return 0;
}
