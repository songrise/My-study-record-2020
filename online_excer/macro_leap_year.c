#include <stdio.h>
#define LEAP_YEAR(y) ((((y) % 4 == 0) && ((y) % 100 != 0)) || ((y) % 400 == 0))

int main(int argc, char const *argv[])
{
    int year;
    scanf("%d", &year);
    putchar(LEAP_YEAR(year) ? 'L' : 'N');

    return 0;
}
