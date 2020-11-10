/*
CH-230-B
a3 p10.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
float product (float a, float b){
//this function make the input a and b product.
    float product;
    product = a * b;
    return product;
}

void productbyref (float a, float b, float *p){
//pointer p equals the product of a and b.
//whatever is in address of *p will also be the value of another float.
    *p = a*b;
}

void modifybyref (float *a, float *b){
//add 3 to pointer a and 11 to pointer b.
//pointer can make these local values global.
    *a = *a+3;
    *b = *b+11;
}

int main(){
    float a, b;
    scanf("%f\n%f", &a, &b);

// a is a, b is b
    printf("The product is %f\n", product(a, b));

// a is ab, b is still b, the product is same with the previous one.
    productbyref(a, b, &a);
    printf("The product by ref is %f\n", a);

// a is ab+3, b is b+11
    modifybyref(&a, &b);
    printf("The modifies by ref are %f and %f", a, b);

    return 0;
}

