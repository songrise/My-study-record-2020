#include <stdio.h>
#define SPACE ' ' 
// 一定要注意单个字符用‘ ’单引号
int main(void)
{
    char ch;
    for (ch = getchar(); ch != '\n'; ch = getchar())
    // getchar() 一次只读取一个字符
        {
            if (ch == SPACE)
        putchar(ch);
        else
        putchar(ch + 1);
        }
    return 0;
}