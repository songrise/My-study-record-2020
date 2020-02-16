#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char str1[40], str2[20];
    scanf("%s", str1);
    scanf("%s", str2);
    strcat(str1, str2);

    printf("%s", str1);
    return 0;
}
