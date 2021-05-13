#include<stdio.h>

int main()
{
    int n = 50;
    int *p = &n;
    printf("This is the address of n: %p\n", p);

    printf("%i\n", *&*p);
    printf("%i\n", *p);

    char *s = "Hi!";
    printf("%s\n", s);
    printf("%c\n", s[0]);
    printf("%c\n", s[1]);
    printf("%c\n", s[2]);

    //*: go to address
    printf("%c\n", *s);
    printf("%c\n", *(s+1));
    printf("%c\n", *(s+2));
}