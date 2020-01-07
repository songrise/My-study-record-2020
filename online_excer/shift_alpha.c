#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    char ch;
    while ((ch = getchar()) != EOF)
    {
        if (isalpha(ch))
        {
            if (ch == 'z')
                putchar('a');
            else if (ch == 'Z')
                putchar('A');
            else
                putchar(ch + 1);
        }
        else
            putchar(ch);
    }
    return 0;
}
