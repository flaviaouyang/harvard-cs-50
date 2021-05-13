#include<stdio.h>
#include<stdlib.h>

// void swap(int, int);
void swap(int*, int*);

int main()
{
    // int x = 1;
    // int y = 2;

    int *x = malloc(sizeof(int));
    *x = 1;
    int *y = malloc(sizeof(int));
    *y = 2;

    printf("before swap: x is %d. y is %i.\n",*x, *y);
    swap(x, y);
    printf("after swap: x is %d. y is %i.\n",*x, *y);
    //output: x is 1. y is 2.
           // x is 1. y is 2.
    // didn't swap. why?
    // bc swap() has their own variables
    // a and b are only copies of x and y
    // changing these variables won't change x and y in the main function
}

// void swap(int a, int b)
// {
//     printf("1: a is %i. b is %i.\n",a, b);
//     int temp = a;
//     a = b;
//     b = temp;
//     printf("2: a is %i. b is %i.\n",a, b);
// }

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
//now it works