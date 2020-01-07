#include <stdio.h>

int is_a_prime(int);

int main(void)
{
    int num;

    scanf("%d", &num);
    if (is_a_prime(num))
        printf("prime");
    else
        printf("not prime");

    return 0;
}

int is_a_prime(int num)
{
    int i = 2;
    for (; i < num; i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}