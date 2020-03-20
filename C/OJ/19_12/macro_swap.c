#include <stdio.h>
#define S(x, y) y, x

int main(int argc, char const *argv[])
{
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    printf("%d %d", S(x, y));

    return 0;
}
