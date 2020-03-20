#include <stdio.h>
#include <stdbool.h>

bool larger_of(int *, int *);
//bool值用于判断是否修改成功

int main()
{
    int num1 = 2, num2 = 3;
    if (larger_of(&num1, &num2))
        printf("%d  %d", num1, num2);

    return 0;
}

bool larger_of(int *x, int *y)
{

    if (*x > *y)
    {
        *y = *x;
        return true;
    }
    else if (*x < *y)
    {
        *x = *y;
        return true;
    }
    else //两数一样
    {
        puts("two num are identical");
        return false;
    }
}