#include<stdio.h>
#include<stdlib.h>

int main()
{
    // most basic way to declare string
    //intentionally not leave space for '\0'
    char *s = malloc(4);
    s[0] = 'H';
    s[1] = 'I';
    s[2] = '!';
    s[3] = '\0';
    //output: seems fine
    //run `valgrind ./a.out`
    //invalid write of size 1
    //invalid read of size 1
    //three bytes in 1 blocks are definitely lost
    printf("%s\n",s);
    free(s);
}