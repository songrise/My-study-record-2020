#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 0;
    int num[4] = {0, 1, 2, 3};
    for (; i < 5; i++)
        printf("%d ", num[i]);
    return 0;
}
