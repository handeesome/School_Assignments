/*
CH-230-B
a3 p8.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
float sum (float number[], int size) {
    int i;
    float sum=0;
//add up all input number to "sum".
//only when it meets -99, it has to take away -99 from "sum"
    for (i=0; i<size; i++){
    sum = sum + number[i];
        if (number[i]==-99){
            sum = sum+99;
        }

    }
    return sum;
}

float average (float number[], int size){
//using the previous sum function to compute the average.
    float average = sum(number, size) / size;

    return average;
}

int main(){
    float number[10];
    int i;
    int size=0;
//input 10 numbers unless the input is -99, which stops.
//size increment every input is entered.
    for (i=0; i<=9; i++){
        scanf("%f", &number[i]);
        size++;
        if (number[i] == -99.0){
        size--;
            break;
        }
    }

    printf("The sum is %f\n", sum(number, size));
    printf("The average is %f\n", average(number, size));

    return 0;

}
