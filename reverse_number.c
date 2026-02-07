# WAP to print the reverse of the number.

#include <stdio.h>

int main()
{
    int num, r, reverse = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    while (num != 0)
    {
        r = num % 10;
        reverse = reverse * 10 + r;
        num = num / 10;
    }

    printf("Reverse number is: %d\n", reverse);

    return 0;
}
