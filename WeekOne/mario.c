#include <stdio.h>

int main (void)
{
     /* declare and instantiate int variable height */
    int height;
    printf("Enter a number for height: ");
     
    /* 
    *use scanf function to take an integer input from the user and
    *store it in height
    */
    scanf("%d", &height);

     /* keep asking for inputs as long as the conditions are satisfied */
    while (height <= 0 || height >= 9){
        printf("Try again. The number should be between 1 and 8. Enter here: ");
        scanf("%d", &height);
        printf("Height: %d\n", height);
    }

    /* use int i to loop through the rows */
    for (int i = 0; i < height; i++){
        /* looping through the columns */
        for (int space = 0; space < height - i; space++){
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++){
            printf("#");
        }
        printf("  ");
        for (int j = 0; j < i + 1; j++){
            printf("#");
        }
        printf("\n");
    }

    return 0;
}
