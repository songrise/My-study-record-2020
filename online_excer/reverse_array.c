#include <stdio.h>
#define LENGTH 10

int main(void)
{
    int num;
    int sorted[10];

    for (int i = 0; i <= LENGTH - 1; i++)
        scanf("%d", &sorted[i]);

    for (int i = LENGTH - 1; i >= 0; i--)
    {
        if (!i)
        printf("%d", sorted[i]);
        else        
        printf("%d ", sorted[i]);        
    }
    return 0;
}
