#include<stdio.h>

int main()
{
    // int x;
    // printf("x: ");
    // scanf("%i", &x);
    // printf("x is %i.\n", x);

    // char *s;
    char s[1040];
    printf("s: ");
    // ampersand is not necessary
    // bc string is already a pointer
    scanf("%s", s);
    printf("s is %s.\n", s);
    //output: s: hello
    //zsh: bus error  ./scan   
    // to solve: char *s = malloc(4);
    //or char s[4];
}