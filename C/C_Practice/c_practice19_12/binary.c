#include <stdio.h>
void to_binary(unsigned long n);

int main(void)
{
    unsigned long number;
    printf("Enter an integer (q to quit): \n");
    while (scanf("%lu", &number) == 1)
    {
        printf("Binary equivalent: ");
        to_binary(number);
        putchar('\n');
        printf("Enter an integer: (q to quit) \n");
    }
    printf("Done. \n");

    return 0;
}

void to_binary(unsigned long n)
{
    int r;

    r = n % 2;
    if (n >= 2)
        to_binary(n / 2);        //这使得不断进入内层
    putchar(r == 0 ? '0' : '1'); //这里倒序地输出结果（恰好是进制转换的性质）
    //直到算到最后一位，才知道第一位应该是什么数字。
    return;
}