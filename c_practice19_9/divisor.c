#include <stdio.h>

int main(void)
{
unsigned long div,num;
char isprime;
printf("please input an integer:");

while((scanf("%d",&num))
                       ==1)//复合，判断expression(删掉==1也恰好可以？)
    {
        for(div=2,isprime=1;(div*div)<=num;div++)
            {
            if(num%div==0)
                {
                 if(div*div==num)
                 printf("%lu is divisible by %d.\n",num,div);
                 else
                 printf("%lu is divisible by %d and %d\n",num,div,num/div);
                 isprime=0;
                }//看作一条expression
            }
    if(isprime)
        printf("%lu is prime.\n",num) ;
    printf("please enter another integer");
    }

    return 0;
}