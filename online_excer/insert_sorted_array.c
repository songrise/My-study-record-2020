#include <stdio.h>
#define LENGTH 10

int main(void)
{
    int num;
    int sorted[10];

    for (int i = 0; i < LENGTH - 1; i++)
        scanf("%d", &sorted[i]);

    scanf("%d", &num);

    for (int i = 0; i < LENGTH - 1; i++)
    {
        if (num >= sorted[i] && num <= sorted[i + 1])
        {   
            printf("%d\n", sorted[i]);
            printf("%d\n",num);
            continue;
        }
        printf("%d\n", sorted[i]);
    }
    return 0;
}