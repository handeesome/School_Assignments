/*
CH-230-B
a8 p7.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
//take two names from the keyboard and then open these two files
    char name1[20], name2[20];
    scanf("%s", name1);
    scanf("%s", name2);
    FILE *file1 = fopen(name1, "r");
    if (file1 == NULL){
        printf (" Cannot open file !\n");
        exit(1);
    }
    FILE *file2 = fopen(name2, "r");
    if (file2 == NULL){
        printf (" Cannot open file !\n");
        exit(1);
    }

//take a double from each file opened
    double d1, d2;
    fscanf(file1, "%lf", &d1);
    fscanf(file2, "%lf", &d2);

//compute the sum difference product and division
    double sum, difference, product, division;
    sum = d1 +d2;
    difference = d1-d2;
    product = d1 * d2;
    division = d1 / d2;

//convert the floats into a string and then write it into "result.txt"
    char string[100];
    sprintf(string, "%lf\n%lf\n%lf\n%lf", sum, difference, product, division);

    FILE *file3 = fopen("results.txt", "w");
    fputs(string, file3);

    fclose(file1);
    fclose(file2);
    fclose(file3);

    return 0;
}
