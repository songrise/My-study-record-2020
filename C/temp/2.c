#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char str1[100], str2[100];
    printf("Please input string 1:");
    scanf("%s", str1);
    printf("Please inpput string 2:");
    scanf("%s", str2);
    printf("Length of str1: %d\n", strlen(str1));
    printf("Length of str2: %d\n", strlen(str2));
    printf("The result of strcmp: %d\n", strcmp(str1, str2));
    strcat(str1, str2);
    printf("concatenate str2 to str1: %s\n", str1);

    return 0;
}
