/*
CH-230-B
a8 p6.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
int main(){
//open "chars.txt" in reading mode
    FILE *temp;
    temp = fopen("chars.txt", "r");
    if (temp == NULL){
        printf (" Cannot open file !\n");
        exit(1);
    }
    char ch;

//create "codesum.txt" and open in writing mode
    FILE *p;
    p = fopen("codesum.txt", "w");
    if (p==NULL){
        printf(" Cannot create file !\n");
        exit(1);
    }
//compute the sum of the first two characters in ASCII
    int sum=0;
    for (int i=0; i<2; i++){
        ch = getc(temp);
        sum = sum+ch;
    }
//convert sum into a string and write the string
//into "codesum.txt"
    char c[10];
    sprintf(c, "%d", sum);
    fputs(c, p);

    fclose(temp);
    fclose(p);

    return 0;
}
