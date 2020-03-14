#include <stdio.h>

int isPositive(int x)
{
    // ‘1’ is mask
    // 0 and positive number share same MSB '0', which makes it hard to indentify by (just checking) MSB.
    // Also it is improper to add or subtract a constant since it may overflow.
    // So the key is to have a "mapping algorithm" to let 0 and neg fllow a same MSB representation.
    return ((~x + 1) >> 31) & 1;
}

int main(int argc, char const *argv[])
{
    if (isPositive(1))
        printf("1Y");
    if (isPositive(0))
        printf("2Y");
    if (isPositive(-1))
        printf("3Y");
    if (isPositive(0x7fffffff))
        printf("4Y");
    if (isPositive(0xffffffff))
        printf("5Y");
    if (isPositive(0x80000000))
        printf("6Y");
    printf("\ntest !\n");
    printf("%d", !!0x89);
    return 0;
}
