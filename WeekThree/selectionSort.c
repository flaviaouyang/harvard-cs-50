#include<stdio.h>

void swap(int*, int*);
int main()
{
    int array[7] = {15, 4, 3, 9, 6, 10, 2};
    int j;
    int min_index;

    for (int i = 0; i < 6; i++)
    {
        min_index = i;
        for (j = i+1; j < 7; j++)
        {
            //find the smallest numbers
            if (array[j] < array[min_index]){
                min_index = j;
            }
        }
        swap(&array[min_index],&array[i]);
    }

    for (int k = 0; k < 7; k++){
        printf("%i\n", array[k]);
    }
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}