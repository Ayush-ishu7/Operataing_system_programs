#WAP to check the given number is prime or not?

#include <stdio.h>

int main()
{
    int a, temp = 0;

    printf("Enter a number: ");
    scanf("%d", &a);

    if (a <= 1)
    {
        printf("%d is not a prime number\n", a);
        return 0;
    }

    for (int i = 2; i <= a / 2; i++)
    {
        if (a % i == 0)
        {
            temp = temp + 1;
            break;
        }
    }

    if (temp == 0)
    {
        printf("%d is a prime number\n", a);
    }
    else
    {
        printf("%d is not a prime number\n", a);
    }

    return 0;
}
