//gcc 5.4.0

#include <stdio.h>
#include <stdlib.h>
#define LEN 10
int main(void)
{
    int arr[LEN];
    for (size_t i = 0; i < LEN; i++)
    {
        arr[i] = rand();
    }

    int max = arr[0];

    for (int i = 0; i < LEN; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("%d", max);

    return 0;
}