/*20191003*/
/*条件表达式*/
#include <stdio.h>
#define coverage 350
int main(void)
{
    int feet;
    int cans;

    printf("enter number of square eet to be painted:\n");
    while(scanf("%d", &feet)==1)
    {
        cans= feet/coverage;
        cans +=((feet%coverage==0))?0:1;//为什么双括号？
        printf("you need %d %s of paint.\n",cans,cans==1?"can":"cans");
        //条件表达式实际上只有一个值 条件？值1：值2
        printf("enter another value");
    }
    return 0;
}