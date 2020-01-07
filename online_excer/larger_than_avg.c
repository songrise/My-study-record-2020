#include <stdio.h>
int main()
{
    int num[10], sum = 0, n = 0;
    float avg;
    for (int i = 0; i < 10; i++)
        scanf("%d", &num[i]);
        //输入数组应该这样
        //而字符串数组只用scanf("%s", array)即可。

    for (int i = 0; i < 10; i++)
        sum += num[i];

    avg = sum / 10;
    for (int i = 0; i < 10; i++)
    {
        if (num[i] > avg)
            n += 1;
    }

    printf("%d", n);
    return 0;
}