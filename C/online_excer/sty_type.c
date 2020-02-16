#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int alpha = 0, num = 0, space = 0, other = 0, c;
    while ((c = getchar()) != '\n') // 关系运算符优先于赋值运算符
    {
        if (isalpha(c))
            alpha++;

        else if (isdigit(c))
            num++;

        else if (isspace(c))
            space++;
        else
            other++;
    }

    printf("%d %d %d %d", alpha, num, space, other);

    return 0;
}