#include <stdio.h>
#define MONTHS 12
int main(void)
{
    const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < sizeof(days) / sizeof(days[0]); i++)
        //sizeof 运算符 给出 它的 运算 对象 的 大小（ 以 字节 为 单位）。 
        //所以 sizeof days 是 整个 数组 的 大小（ 以字节 为单位），sizeof day[0]是 数组中 一个元素 的大小（ 以字节为 单位）。
        //整个 数组 的 大小 除以 单个 元素 的 大小 就是数组元素的个数。
        printf("Month %2d has %2d days. \n", i + 1, days[i]);

    return 0;
}