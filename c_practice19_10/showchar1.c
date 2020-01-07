/* showchar1. c -- 有 较大 I/ O 问题 的 程序 */ 
#include <stdio.h> 
void display(char cr, int lines, int width);
int main(void) 
{ip
    int ch; /* 待 打印 字符 */ 
    int rows, cols; /* 行数 和 列数 */ 
    printf(" Enter a character and two integers:\n");
    while ((ch = getchar()) != '\n') 
    { 
        scanf("%d %d", &rows, &cols);
        display(ch, rows, cols);
        printf("Enter another character and two integers;\n");
        printf("Enter a newline to quit.\n");
    } 
    printf(" Bye.\n");
    return 0;
} 
void display(char cr, int lines, int width) 
{ 
    int row, col;
    for (row = 1; row <= lines; row++) 
    { 
        for (col = 1; col <= width; col++)
    putchar( cr);
    putchar('\n'); /* 结束一行并开始新的一行 */ 
    } 
}
