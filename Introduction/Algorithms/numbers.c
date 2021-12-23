#include<stdio.h>

int main(void)
{
    //linear search implementation
    int numbers[7] = {1, 3, 4, 5, 7, 8, 9};

    int search = 1;
    //find 4
    for (int i = 0; i < 7; i++){
        if (numbers[i] != 9){
            search += 1;
            // printf(" %i searches\n", search);
            if (search == 8){
                printf("cannot be found.\n");
                return 1;
            }
        } else {
            printf("this takes %i searches.\n", search);
            return 0;
        }
    }
}