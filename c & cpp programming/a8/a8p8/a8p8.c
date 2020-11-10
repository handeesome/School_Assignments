/*
CH-230-B
a8 p8.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
int main(){
//open "text1.txt" and "text2.txt" in appending mode
//after appending "\n" to each file, close files
    FILE *file1 = fopen("text1.txt", "a");
    if (file1 == NULL){
        printf (" Cannot open file !\n");
        exit(1);
    }
    FILE *file2 = fopen("text2.txt", "a");
    if (file2 == NULL){
        printf (" Cannot open file !\n");
        exit(1);
    }
    fputs("\n", file1);
    fputs("\n", file2);
    fclose(file1);
    fclose(file2);

//create "merge12.txt" and open the previous two files in
//reading mode
    FILE *file3 = fopen("merge12.txt", "w");
    file1 = fopen("text1.txt", "r");
    if (file1 == NULL){
        printf (" Cannot open file !\n");
        exit(1);
    }
    file2 = fopen("text2.txt", "r");
    if (file2 == NULL){
        printf (" Cannot open file !\n");
        exit(1);
    }

//read line by line in each file and merge them together
    char line1[500];
    char line2[500];
    while(!feof(file1) || !feof(file2)){
        fgets(line1, 500, file1);
        fgets(line2, 500, file2);


        if(!feof(file1)){
            fputs(line1, file3);
        }
        if(!feof(file2)){
            fputs(line2, file3);
        }
    }
    fclose(file1);
    fclose(file2);
    fclose(file3);

    return 0;

}
