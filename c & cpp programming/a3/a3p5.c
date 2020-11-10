/*
CH-230-B
a3 p5.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
double Sum(double Celsius[], int size){
    double sum=0;
//start from sum=0, add every value to "sum" until the end of array.
    for (int i=0; i<size; i++){
        sum = sum + Celsius[i];
    }
    printf("The sum of the temperatures is %lf", sum);

    return sum;
}

double List(double Celsius[], int size){
//start from position 0, print the temperature list until the end of array.
    for (int i=0; i<size; i++){
        printf("%lf\n", Celsius[i]);
    }

    return 0;
}

double Fahrenheit(double Celsius[], int size){
    double result;
//every loop run has a new Fahrenheit result and is printed.
    for (int i=0; i<size; i++){
        result = 9/5.0 * (Celsius[i]) +32;
        printf("%lf\n", result);
    }

    return 0;
}

double Mean(double Celsius[], int size){
    double mean;
//using the preview Sum function to compute the mean.
    mean = Sum(Celsius, size) / size;
    printf("The mean of the temperatures is %lf", mean);

    return mean;
}

int main(){
    char c;
    int n;
    scanf("%c", &c);
    scanf("%d", &n);
//inputting temperatures until the end of the array.
    double temp[n];
    int i;
    for (i=0; i<n; i++){
        scanf("%lf", &temp[i]);
    }
//different cases of character c has different outcomes.
    switch(c){
    case 's':
        Sum(temp, n);
        break;
    case 'p':
        List(temp, n);
        break;
    case 't':
        Fahrenheit(temp, n);
        break;
    default:
        Mean(temp, n);
    }

    return 0;
}
