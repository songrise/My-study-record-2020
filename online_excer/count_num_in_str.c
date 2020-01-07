#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    char ch;
    int count = 0;
    while ((ch = getchar()) != EOF)
    {
        if (isalpha(ch))
            count++;
    }
    printf("%d", count);

    return 0;
}
