#include <stdio.h>
int main(void)
{
    int num;

    printf("n    n cubed\n");
    for(num=1;num<=8;num++)
    {
        printf("%2d    %3d\n",num,num*num*num);
    }
    return 0;
}