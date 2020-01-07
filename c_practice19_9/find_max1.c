#include <stdio.h>
//存在意外的bug
int main(void)
{
    int list[6];
    int index=0;
    int n=0;
    printf("please input 6 positive int:\n");
    scanf("%d",&list);

    for(;index<=5;index++)
    {
        if(list[index]>n)
        n=list[index];
    }
    printf("the largest num in list is %d",n);
    return 0;
}


