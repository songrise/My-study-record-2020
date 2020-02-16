#include <stdio.h>
#define S(x, y) ((x) % (y))

int main(int argc, char const *argv[])
{
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    printf("%d", S(x, y));

    return 0;
}
