#include <stdio.h>
int substitute_vowels(char* s, char ch){
    char* ptr = &*s;
    int count = 0;
    int i=0;
    while(ptr[i]){
        if (ptr[i]=='a' || ptr[i]=='e' || ptr[i]=='i'
            || ptr[i]=='o' || ptr[i]=='u'){
            ptr[i] = ch;
            count++;
        }
        i++;
    }
    return count;
}
int main() {
    char s[] = "This is a sentence";
    printf("%s\n", s);
    int n = substitute_vowels(s, 'o');
    printf("%s\n", s);
    printf("%d\n", n);

}
