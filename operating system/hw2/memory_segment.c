#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *strdup(const char *s){

    char *p = NULL;
    size_t len;
    if (s) {
        len = strlen(s);
        printf("%d\n", len);
        p = malloc(len+1);
        if (p) {
            strcpy(p, s);
        }
    }
    return p;
}

int main(){

    static char m[] = "Hello World!";
    char *p = strdup(m);
    if (!p) return EXIT_FAILURE;

    return (puts(p) == EOF);
}

