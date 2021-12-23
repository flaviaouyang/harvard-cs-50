#include <stdio.h>

int main (void)
{
    /* take the credit number as an user input */
    long long num;
    printf("Enter you card number below.\n");
    scanf("%lld", &num);  
    printf("Input number is: %lld\n", num);

    /* convert the long to an int array */
    int digits[16];
    for (int i = 15; i >= 0; i--){
        digits[i] = num % 10;
        num = num / 10;
    }

    /* check if conversion works */
    /* for (int check = 0; check < 16; check++){
        printf("%d", digits[check]);
    } */

    int stepOne = 0;
    for (int i = 0; i <= 14; i+=2){
            stepOne += digits[i] * 2;
    }

    printf("%d", stepOne);
}