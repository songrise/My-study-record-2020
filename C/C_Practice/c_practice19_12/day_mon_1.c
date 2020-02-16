#include <stdio.h>
#define MONTHS 12

int main(void)
{
    const int days[MONTHS] = {31,28,31,30,31,30,31,31,30,31,30,31};
    //声明数组时方括号内可以留空，若留空，则自动按花括号匹配数组长度
    int index;
    for (index = 0; index<MONTHS; index++)
        printf("Month %2d has %2d days. \n", index+1, days[index]);
        
    return 0;
}