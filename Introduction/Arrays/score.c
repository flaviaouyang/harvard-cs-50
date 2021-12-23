#include<stdio.h>

float score_sum(int, int[]);

int main(void)
{
    int size = 0;
    printf("Total number of scores to be entered: ");
    scanf("%i", &size);
    /* printf("size of scores are: %i.\n", size); */

    int use = size;
    // printf("use is: %i.\n", use);

    int place = size;
    // printf("place is: %i.\n", place);

    printf("\n");
    int score [size];
    for (int i = 0; i < place; i++){
        int num;
        printf("Enter score: ");
        scanf("%i", &num);

        score[i] = num;
    }
    printf("\n");

    float addition_sum = score_sum(use, score);
    float average_score = addition_sum / use;
    printf("Average score is %.3f.\n", average_score);
}

float score_sum(int input, int array[])
{
    float sum = 0;
    for (int j = 0; j < input; j++)
    {
        // printf("input is %i.\n", input);
        // printf("j is %i.\n", j);
        sum += array[j];
        // printf("sum is %f.\n", sum);
    }
    return sum;
}