#include <stdio.h>
int trystat(void);

int main(void)
{
    int count;

    for (count = 1; count <=3; count++)
    {
        printf("Here comes iteration %d\n", count);
        trystat();

    }
    return 0;

}

int trystat(void)
{
    int fade = 1;
    static int stay = 1;
    //static 不会在每次call func 的时候重复初始化stay 为1.

    printf("fade = %d and stay = %d\n", fade++, stay++);

}