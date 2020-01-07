#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char ch, i = 0;
    while ((ch = getchar()) != EOF)
    {
        if (ch == ' ')
            continue;
        putchar(ch);
    }

    return 0;
}
