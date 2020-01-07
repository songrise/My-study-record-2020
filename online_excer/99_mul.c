#include <stdio.h>
int main(void)
{
    int j = 1;
    for (; j <= 9; j += 1)
    {
        for (int i = 1; i <= j; i++)
            {
            printf("%d*%d=%d", i, j, i * j);
            puts(' ');
            }
        printf("\n");
    }
    return 0;
}