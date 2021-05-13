#include<stdio.h>

void swap(int*, int*);

int main()
{
    int arr[8]= {2, 1, 13, 7, 5, 11, 9, 3};
    int i, j;
    // swap pairs of numbers repeatedly until all sorted
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 7-i; j++)
        if (arr[j] > arr[j+1])
        {
            swap(&arr[j], &arr[j+1]);
        }
    }

    // print out the array
    for(int k = 0; k < 8; k++)
    {
        printf("%i", arr[k]);
        printf(" ");
    }
    printf("\n");
}

void swap(int *i, int* j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}