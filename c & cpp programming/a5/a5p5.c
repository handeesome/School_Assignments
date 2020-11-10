/*
CH-230-B
a5 p5.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
//this function calculates the scalar product of vector v and w
//which is the sum of v[i]*w[i]
double scalar_product(double* v, double* w, int components){
    double scalar_product = v[0]*w[0];
    for (int i=1; i<components; i++){
        scalar_product = scalar_product + v[i]*w[i];
    }
    return scalar_product;
}
//this function finds out the smallest and largest component of a vector
//as well as the respective position
void lar_sma_pos(double* v, int components){
    float smallest = v[0], largest = v[0];
    int pos_sma = 0, pos_lar = 0;
    for (int i=0; i<components; i++){
        if (smallest>v[i]){
            smallest = v[i];
            pos_sma = i;
        }
        if (largest<v[i]){
            largest = v[i];
            pos_lar = i;
        }
    }
    printf("The smallest = %lf\n", smallest);
    printf("Position of smallest = %d\n", pos_sma);
    printf("The largest = %lf\n", largest);
    printf("Position of largest = %d\n", pos_lar);
}
int main(){
    int n;
    double *v, *w;
    scanf("%d", &n);
    v = malloc(sizeof(double)*n);
    if (v==NULL){
        exit (1);
    }
    w = malloc(sizeof(double)*n);
    if (w==NULL){
        exit(1);
    }
//only knows the size of the arrays can they be scanf from the keyboard
    for (int i=0; i<n; i++){
        scanf("%lf", &v[i]);
    }
    for (int i=0; i<n; i++){
        scanf("%lf", &w[i]);
    }
    printf("Scalar product=%lf\n", scalar_product(v, w, n));
    lar_sma_pos(v, n);
    lar_sma_pos(w, n);
}
