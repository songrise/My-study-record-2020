#include <stdio.h>

int *shift(int len, int m, int *arr);
int main()
{
    int n, m;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i <= n - 1; i++)
    {
        scanf("%d", &arr[i]); // 指定了下标就一定要加取址符&。
    }

    scanf("%d", &m);
    int *shifted = shift(n, m, arr);

    for (int i = 0; i <= n - 1; i++)
    {
        printf("%d ", shifted[i]);
    }

    return 0;
}

int *shift(int len, int m, int *arr)
{
    int shifted[len];
    int i, j;
    for (i = len - m, j = 0; j <= len - 1; j++, i++)
    {
        shifted[j] = arr[i];
        if (i == len - 1)
            i = -1; //注意不是0因为for循环更新条件 i++。
    }

    for (int i = 0; i <= len - 1; i++)
    {
        arr[i] = shifted[i];
    }
    return arr;
}