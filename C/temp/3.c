#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char str[100];
    printf("Please input an string:");
    scanf("%s", str);

    fflush(stdin); //discard trailing \n in buffer.
    char target;
    int count = 0;
    printf("Please input the char to find: ");
    scanf("%c", &target);

    int len = strlen(str);
    for (size_t i = 0; i < len; i++)
    {
        if (str[i] == target)

            count += 1;
    }
    if (count)
    {
        printf("%c found %d times in string!", target, count);
    }
    else
    {
        printf("%c not found in string!\n", target);
    }

    return 0;
}
