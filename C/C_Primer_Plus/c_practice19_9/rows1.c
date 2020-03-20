#include <stdio.h>
//a nested loop
int main(void)
{
    int row;
    char ch;
    for(row=0; row<6; row ++)
    {
        for(ch='A'; ch<('A'+row); ch++)
        printf("%c",ch);//inner loop body 是一条简单语句
        printf("\n");//注意此语句属于外层循环
    }
    
    return 0;
}