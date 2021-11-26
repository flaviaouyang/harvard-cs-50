#include<stdio.h>

void draw(int);

int main()
{
    int height;
    printf("enter the height: ");
    scanf("%i", &height);
    // printf("height is %i.\n", height);
    draw(height);
}

void draw(int x)
{
    //base case
    if (x == 0)
    {
        return;
    }

    draw(x - 1);

    for(int i = 0; i < x; i++)
    {
        printf("#");
    }
    printf("\n");

    // draw(x - 1);
}