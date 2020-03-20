#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int *get_10_num(void);
bool change(int *);
bool prt_arr(int *);

int main()
{
    int *arr;

    arr = get_10_num();
    change(arr);
    prt_arr(arr);

    return 0;
}

int *get_10_num(void)
{
    int *arr;
    arr = (int *)malloc(10 * sizeof(int));

    for (int i = 0; i <= 9; i++)
        scanf("%d", &arr[i]);

    return arr;
}

bool change(int *arr)
{
    int min = arr[0], max = arr[0];

    for (int i = 0; i <= 9; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            continue;
        }

        if (arr[i] < min)
        {
            min = arr[i];
            continue;
        }
    }

    int temp;
    for (int i = 0; i <= 9; i++)
    {
        if (arr[i] == max)
        {
            temp = arr[i];
            arr[i] = arr[9];
            arr[9] = temp;
        }

        if (arr[i] == min)
        {
            temp = arr[i];
            arr[i] = arr[0];
            arr[0] = temp;
        }
    }

    return 1;
}

bool prt_arr(int *arr)
{
    for (int i = 0; i <= 9; i++)
        printf("%d ", arr[i]);

    return true;
}
