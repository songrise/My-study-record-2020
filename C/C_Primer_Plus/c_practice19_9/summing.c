#include <stdio.h>

int main(void)
{
    long num;
    long sum=0L;
    char status;//实际上char是一个unsigned一字节的容器

    printf("please enter an integer to be sumed:");
    printf("(q to quit):   ");
    status=scanf("%ld",&num);//created a poiner by&
    while(status==1)//status值为循环条件，其值取决于scanf的返回值
    {
        sum=sum+num;
        printf("please enter an integer to be sumed (q to quit):  ");
        status=scanf("%ld", &num);
    }
    //实际上任何无法被scanf识别输入，（导致scanf 返回非1值 都会导致程序结束）
    printf("Those integers sum to %ld \n", sum);

    return 0;
}