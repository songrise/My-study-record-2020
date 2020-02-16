#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

bool IsIsogram(char *str);
int main(void)
{
    char str[1] = "";
    if (IsIsogram(str))
        printf("Yes");
    else
    {
        printf("NO");
    }

    return 0;
}

bool IsIsogram(char *str)
{
    int i, j, len;
    len = sizeof(str);
    for (i = 0; i <= len; i++)
    {
        str[i] = tolower(str[i]);
        for (j = i + 1; j < len; j++)
        {
            str[j] = tolower(str[j]); //字符串是const数组。不可以这样改。
            if (str[j] == str[i])
                return false;
        }
    }
    return true;
}
