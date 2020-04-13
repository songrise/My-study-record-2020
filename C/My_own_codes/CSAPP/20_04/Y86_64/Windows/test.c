#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char test[20] = ".test";
    char temp[20];
    printf("%s\n", test + 1);
    strncpy(temp, test + 1, 20);
    printf("%s", temp);

    return 0;
}
