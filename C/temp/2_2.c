#include <stdio.h>
#define ARRLEN 9

int main(int argc, char const *argv[])
{
    int a[ARRLEN] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int sum = 0;
    for (size_t i = 0; i < ARRLEN; i++)
    {
        if (!(a[i] % 2))
            sum += a[i];
    }
    printf("The sum of all even elements in array is %d\n", sum);

    return 0;
}
