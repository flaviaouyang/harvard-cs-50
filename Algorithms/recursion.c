#include<stdio.h>

//promise
void greet(int n);
void countdown(int i);
int sumN(int j);
int sum = 0;
int gridPath(int, int);
int path;

int main()
{
    // this is a program trying out recursion
    // greet(3);
    // countdown(5);
    // printf("%i\n", sumN(25));
    // printf("%i\n", gridPath(2,4));
}

void greet(int n)
{
    //base case
    if(n == 0){
        printf("finished\n");
    } else {
        printf("Hi.\n");
        n -= 1;
        greet(n);
    }
}

void countdown(int i)
{
    //base case
    if (i == 0){
        printf("0\n");
    } else {
        printf("%i\n",i);
        i -= 1;
        countdown(i);
    }
}

int sumN(int j)
{
    // find the sum of integer 1 to j
    //base case
    if (j == 0){
        return sum;
    } else {
        return j + sumN(j-1);
    }
}

int gridPath(int n, int m)
{
    if (n == 1 || m == 1){
        path = 1;
    } else {
        path = gridPath(n-1,m) + gridPath(n,m-1);
    }
    return path;
}