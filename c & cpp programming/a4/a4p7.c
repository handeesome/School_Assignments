/*
CH-230-B
a4 p7.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
int main(){
    int arr[30][30];
    int r, c, n;
    scanf("%d", &n);
    for (r=0; r<n; r++){
        for (c=0; c<n; c++){
            scanf("%d", &arr[r][c]);
        }
    }

    printf("The entered matrix is:\n");
    for (r=0; r<n; r++){
        for (c=0; c<n; c++){
            if (c==n-1){
                printf("%d \n", arr[r][c]);
            }
            else{
                printf("%d ", arr[r][c]);
        }
    }
    }
    printf("Under the main diagonal:\n");
    for (r=0; r<n; r++){
        for (c=0; c!=r ; c++){
            printf("%d ", arr[r][c]);
            if (r==n-1 && c==n-2){
                printf("\n");
            }
        }


    }
    return 0;
}

