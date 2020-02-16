#include <stdio.h>
int tadd_ok(int, int);

int main(int argc, char const *argv[])
{
    if (tadd_ok(1, 2))
        printf("yes");
    if (tadd_ok(2147483635, 900))
        printf("yes");
    return 0;
}
int tadd_ok(int x, int y)
{
    return (x + y > x);
}