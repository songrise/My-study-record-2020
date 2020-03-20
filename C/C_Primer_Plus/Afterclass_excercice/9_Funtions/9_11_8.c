#include <stdio.h>
#include <stdlib.h>

double power(double num, int p);

int main()
{
    int number, times;
    double ans;
    puts("please input a number:");
    scanf("%ld", &number);
    puts("\nentre the power:");
    scanf("%d", &times);

    ans = power(number, times);
    printf("the answer is %d", ans);

    return 0;
}

double power(double num, int p)
{
    if (p < 0)
    {
        printf("power should not be negative");
        exit(EXIT_FAILURE);
    }

    if (num == 0 && p == 0)
    {
        printf("undefined");
        exit(EXIT_FAILURE);
    }

    if (p == 0)
    {
        return 1;
    }
    else
    {
        return num * power(num, p - 1);
    }
}