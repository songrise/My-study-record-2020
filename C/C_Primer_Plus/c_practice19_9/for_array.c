#include <stdio.h>
#define SIZE 10
#define PAR 72
int main(void)
{
    int index, score[SIZE], sum=0;
    float average;

    printf("Enter %d golf scores:\n",  SIZE);
    for(index = 0 ; index< SIZE; index++)
        scanf("%d",  &score[index]); //读取输入的分数，并且存在数组里
        
    printf("The scores read in are as follows:\n");
    for (index=0;index<SIZE;index++)
        printf("%5d", score[index]); //读取数组存储的数据，然后printf
    printf("\n");
    for(index=0;index<SIZE;index++) //读取数组存储数据，然后依次求和。
        sum+=score[index];
    average=(float) sum/ SIZE; //强制类型转换
    printf("Sum of scores = %d,average=%.2f\n", sum,average);
    printf("Thats a handicap of %.0f.\n",average - PAR);

    return 0;

}