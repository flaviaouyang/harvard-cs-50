#include<stdio.h>

int main()
{
    int n = 50;
    int *p = &n;
    printf("This is the address of n: %p\n", p);

    printf("%i\n", *&*p);
    printf("%i\n", *p);
}