#include<stdio.h>
int main()
{
    int numbers[20];
    int neg=0, sum=0, pos=0;
    for (int i = 0; i<=19; i++)
        scanf("%d",&numbers[i]);
        
    for (int i =0; i<=19; i++)
    {
        if (numbers[i]<0)
            neg+=1;
        else if (numbers[i]>0)
        {
            sum+=numbers[i];
            pos += 1;
        }
    }
printf("%d\n%.2f",neg,((float)sum)/pos);

return 0;
}