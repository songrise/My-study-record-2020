#include <stdio.h>
#define SPACE ' '

int main(void)
{
    char ch;
    ch=getchar();
    while(
        (ch=getchar())
                        !='\n')//把 读取 和 测试 合并 成 一个 表达式。
    {
        if (ch==SPACE)
            putchar(ch);
        else
        {
            putchar(ch+1);//ascii+1
        }
    }
    putchar(ch);

    return 0;
}
