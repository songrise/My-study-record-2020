#include <stdio.h>
#include <stdlib.h>
void reverseString(char *, int);

int main(int argc, char const *argv[])
{
    char string[5] = {'h', 'e', 'l', 'l', 'o'};
    reverseString(string, 5);
    for (int i = 0; i < 5; i++)
        printf("%c ", string[i]);

    return 0;
}

void reverseString(char *s, int sSize)
{
    static char i = 0, j = 0;
    char *temp = malloc(sizeof(int));
    char *toSwap;

    if (i == sSize)
        return;

    else
    {
        i++;
        // printf("i=%d ", i); //??????
        reverseString(s + 1, sSize);
        toSwap = s - i + 1 + j;

        if (j <= i)
        {
            *temp = *s;
            *s = *toSwap;
            *toSwap = *temp;
        }

        j++;
        i--;
    }
}
