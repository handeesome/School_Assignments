/*
CH-230-B
a3 p4.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
int position(char str[], char c){
    int idx;
    /* Loop until end of string */
    for (idx = 0; str[idx] != c && str[idx] != '\0'; idx++){
        //Without "{}", for loop will return to idx, not running the loop.
        //Nothing to execute is exactly the loop is doing, not returning to 0.
    }
    /* do nothing */
    return idx;
}
int main() {
    char line[80];
    while (1) {
    printf("Enter string:\n");
    fgets(line, sizeof(line), stdin);
    printf("The first occurrence of 'g' is: %d\n", position(line, 'g'));
    }

    return 0;
}
