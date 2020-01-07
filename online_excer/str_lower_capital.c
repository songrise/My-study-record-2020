#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    char str[100];
    scanf("%[^\n]", str);
    //scanf高级语法
    //https://baijiahao.baidu.com/s?id=1598528179939861970&wfr=spider&for=pc
    int len = strlen(str);
    for (int i = 0; i <= len - 1; i++)
    {
        if (isupper(str[i]))
            str[i] += 32;
        // str[i] == toupper(str[i])
    }
    printf("%s", str);
    return 0;
}
