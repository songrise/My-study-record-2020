#include <stdio.h>

int is_vowel(char);

int main(void)
{
    static char str[100];
    scanf("%s", str);
    for (int i = 0; i <= sizeof(str); i++)
    {
        if (is_vowel(str[i]))
            putchar(str[i]);
    }
    return 0;
}

int is_vowel(char alpha)
{
    return (alpha == 'a' || alpha == 'e' || alpha == 'i' || alpha == 'o' || alpha == 'u' ||
            alpha == 'A' || alpha == 'E' || alpha == 'I' || alpha == 'O' || alpha == 'U');
}