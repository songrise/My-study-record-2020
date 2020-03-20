#include <stdio.h>
int main(void)
{
    int num, a = 0, b = 0, c = 0;
    scanf("%d", &num);
    a = num / 100;
    b = (num - 100 * a) / 10;
    c = (num - 100 * a - 10 * b);
    printf("%d", a * a * a + b * b * b + c * c * c == a * 100 + b * 10 + c);

    return 0;
}