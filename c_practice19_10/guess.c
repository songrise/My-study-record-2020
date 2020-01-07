/* guess. c --一个拖沓且错误的猜数字程序*/
#include <stdio.h>
int main(void)
{
    int guess = 1;

    printf("Pick an int from q to 100. I will try to guess ");
    printf("it.\n Respond with a y if my guess is right and with");
    printf("Uh... is your number %d?\n", guess);
    while (getchar() != 'y')   //换行符也被读取了
    {
        printf("well, then is it %d?\n", ++guess);       
    }
    printf("I knew i could do it!\n");
    
    return 0;
}
