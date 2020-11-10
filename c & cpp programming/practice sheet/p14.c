#include <stdio.h>
int main(){
    FILE *a = fopen("generate.txt", "w");
    int num, square;
    char space = ' ';
    char newline = '\n';

    for (int i=1; i<=100; i++){
    num = i;
    square = i*i;

    fwrite(&num, sizeof(int), sizeof(num), a);
    fwrite(&space, sizeof(char), sizeof(square), a);
    fwrite(&square, sizeof(int), sizeof(space), a);
    fwrite(&newline, sizeof(char), sizeof(square), a);

    }

    fclose(a);
}
