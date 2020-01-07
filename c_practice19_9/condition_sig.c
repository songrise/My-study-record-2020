#include <stdio.h>
int main(void)
{
    int num;
    while(1)
    {
        printf("please input an int:");
        scanf("%d",&num);
        if (num < 0 || num > 10)
        {
            printf("the num should not be negative nor larger than 10\n");
            continue;
        }
        printf("congratulation!\n");
        break;
    }

    return 0;
}