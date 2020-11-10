/*
CH-230-B
a4 p3.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
#include <math.h>
float geometric_mean(float arr[], int num){
    float product=1;
//multiply every element with the last product
    for (int i=0; i<num; i++){
        product = product * arr[i];
    }
//gm is the n root of product of n elements
    float geometric_mean = pow(product, (float)1/num);

    return geometric_mean;
}

float highest(float arr[], int size){
    float highest=arr[0];
//compare each element with the current highest
//to get the highest
    for (int i=0; i<size; i++){
        if (highest<arr[i]){
            highest = arr[i];
        }
    }
    return highest;
}

float smallest(float arr[], int size){
    float smallest=arr[0];
//compare each element with the current smallest
//to get the smallest
    for (int i=0; i<size; i++){
        if (smallest>arr[i]){
            smallest = arr[i];
        }
    }
    return smallest;
}

float sum(float arr[], int size){
    float sum=0;
//adding each element into sum
    for (int i=0; i<size; i++){
        sum = sum+arr[i];
    }
    return sum;
}
int main(){
    float array[15];
    int size=0;
//inputting values, every time an element is input
//size increment
    for (int i=0; i<15; i++){
        printf("Please enter number %d: ", i+1);
        scanf("%f", &array[i]);
        size++;
        if (array[i]<0){
            array[i]=1;
            size--;
            break;
        }
    }
    char c;
    printf("Please enter m, h, l or s: ");
    getchar();
    scanf("%c", &c);

    switch (c){
    case 'm':
        printf("The geometric mean of the array is %f", geometric_mean(array, size));
    break;
    case 'h':
        printf("The highest number in the array is %f", highest(array, size));
    break;
    case 'l':
        printf("The smallest number in the array is %f", smallest(array, size));
    break;
    case 's':
        printf("The sum of all elements in the array is %f", sum(array, size));
    break;
    }

    return 0;
}
