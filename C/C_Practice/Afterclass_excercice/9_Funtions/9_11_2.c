#include <stdio.h>

void chline(char, int, int);

int main(void)
{
    chline('s', 8, 2);

    return 0;
}

void chline(char ch, int i, int j)
{
    int line = 1, column;
    while (line <= i)
    {
        column = 0;
        while (column < j)
        {
            putchar(ch);
            column++;
        }

        putchar('\n');
        line++;
    }
}