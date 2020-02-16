#include <stdio.h>
int main(void)
{
    int num, i;
    printf("Please input an num: ");
    scanf("%d", &num);

        for (i = 0; i < 10; i++)
    {
        printf("%d\n", num - 5 + i);
    }
    return 0;
}

