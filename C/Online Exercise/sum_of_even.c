#include <stdio.h>
int main()
{
    int times;
    float temp, i = 2, j = 1, n = 0, sum = 0;
    scanf("%d", &times);
    for (int index = 0; index < times; index++)
    {
        sum += i / j;
        temp = i;
        i += j;
        j = temp;
    }
    printf("%.2f", sum);
    return 0;
}