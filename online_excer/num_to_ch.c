#include <stdio.h>

int main(void)
{
    char number[5];
    scanf("%s", number);

    for (int i = 0; i < 4; i++)
        printf("%c ", number[i]);
    return 0;
}