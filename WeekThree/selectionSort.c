#include<stdio.h>

int main()
{
    int array[7] = {15, 4, 3, 9, 6, 10, 2};
    int smallest = array[0];
    //find the smallest number
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (array[j] < smallest){
            smallest = array[i];
            }
        }
        int temp = array[i];
        array
    }
}