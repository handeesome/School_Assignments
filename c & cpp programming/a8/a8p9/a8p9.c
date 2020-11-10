/*
CH-230-B
a8 p9.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
//input file name and read it
int main(){
    char filename[20];
    scanf("%s", filename);
    FILE *file = fopen(filename, "r");
    if (file == NULL){
        printf(" Cannot open file! \n");
    }

//read one char by one, if it meets requirement, set temp to 1
//and count++, in case the next is still one requirement, compare both
//temps and make sure multiple only count as one word
    char c;
    int count=0;
    int temppre = 0, tempnext = 0;
    while (!feof(file)){
            c = getc(file);
            if(c==' ' || c==',' || c=='?' || c=='!'
               || c=='.' || c=='\t' || c=='\r' || c=='\n'){
                tempnext = 1;
                if (tempnext == temppre){
                    temppre = 1;
                }
                else{
                    count++;
                    temppre = 1;
                }
            }
            else {
                temppre = 0;
            }
    }
    printf("The file contains %d words.", count);
}
