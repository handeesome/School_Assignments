#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct person {
    char name[30];
    int age;
};

void bubbleSortint(struct person *p, int n)
{
    int temp_age;
    char temp_name[30];
    for (int i = 0; i < n-1; i++){

        for (int j = 0; j < n-i-1; j++){
            if ((p+i)->age > (p+i+1)->age){
                temp_age = (p+i+1)->age;
               //temp_name = (p+i+1)->name;
               strcmp(temp_name, (p+i+1)->name);
                (p+i)->age = (p+i+1)->age;
              //  (p+i)->name = (p+i+1)->name;
              strcmp((p+i)->name, (p+i+1)->name);
                (p+i+1)->age = temp_age;
             //   (p+i+1)->name = temp_name;
             strcmp((p+i+1)->name, temp_name);
           }
       }
   }
}
void sortStrings(char arr[][100], int n)
{
    char temp[100];

    for (int j=0; j<n-1; j++)
    {
        for (int i=j+1; i<n; i++)
        {
            if (strcmp(arr[j], arr[i]) > 0)
            {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[i]);
                strcpy(arr[i], temp);
            }
        }
    }
}
void printstruct(struct person *p, int n){
    for (int i=0; i<n; i++){
        printf("{%s %d} ", (p+i)->name, (p+i)->age);
    }
    printf("\n");
}

int main()
{
    struct person *p;
    int n;
    scanf("%d", &n);
    p = (struct person*)malloc(sizeof(struct person)*n);
    for (int i=0; i<n; i++){
        scanf("%s\n%d", (p+i)->name, &(p+i)->age);
    }
    bubbleSortint(p, n);
    printstruct(p, n);
    return 0;
}
