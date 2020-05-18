#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char str[100];
    printf("Please input an string:");
    scanf("%s", str);
    printf("str reversed:");
    int len = strlen(str);

    for (int i = len; i >= 0; i--)
    {
        putchar(str[i]);
    }

    return 0;
}
