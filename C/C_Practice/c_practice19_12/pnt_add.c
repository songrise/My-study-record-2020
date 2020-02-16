#include <stdio.h>
#define SIZE 4
int main(void)
{
    short dates[SIZE];
    short *pti;
    short i;
    double bills[SIZE];
    double *ptf;
    pti = dates;
    ptf = bills;

    printf("%23s %15s\n", "short", "double");
    for (i = 0; i < SIZE; i++)
        printf("pointers + %d: %10p %10p\n", i, pti + i, ptf + i);
    //见教材cpp10.3
    //对于数组而言，index +1对应的地址是下一个元素的地址而非下一个byte的地址
    //因此指针需要声明类型，因为不同类型占byte可能不同。
    return 0;
}