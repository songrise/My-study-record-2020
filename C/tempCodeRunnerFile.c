#include <stdio.h>

int main(void)
{
    int arr[100], arrLen = 0, i;
    printf("Input data (-1 to stop): ");
    while (1)
    {
        int temp;
        scanf("%d", &temp);
        if (temp == -1)
            break;
        else
        {
            arr[arrLen++] = temp;
        }
    }
    //reverse
    int j = arrLen;

    for (i = 0; i < arrLen / 2; i++)
    {
        int temp;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j--] = temp;
    }

    for (i = 0; i < arrLen; i++)
    {
        printf("%d ", arr[i]);
    }
}