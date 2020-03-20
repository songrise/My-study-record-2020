#include <stdio.h>
int is_a_shuixianhua(int);

int main()
{
    for (int i = 100; i <= 999; i++)
    {
        if (is_a_shuixianhua(i))
                printf("%d\n", i);
    }

    return 0;
}

int is_a_shuixianhua(int num)
{
    int a = 0, b = 0, c = 0;
    a = num / 100;
    b = (num - 100 * a) / 10;
    c = (num - 100 * a - 10 * b);
    return (a * a * a + b * b * b + c * c * c == a * 100 + b * 10 + c);
}