#include <stdio.h>
int main(void)
{
    int m =1;
    while (m++<10)//这是一个序列点，此处m已经更新；所以下面会打印23456789
    {
        printf("%d\n",m);

    }
    return 0;
}