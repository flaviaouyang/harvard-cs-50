#include <stdio.h>

int main (void)
{
    int height;
    printf("Enter a number for height: ");
    scanf("%d", &height);

    while (height <= 0 || height >= 9){
        printf("Try again. The number should be between 1 and 8. Enter here: ");
        scanf("%d", &height);
        printf("Height: %d\n", height);
    }

    for (int i = 0; i < height; i++){
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