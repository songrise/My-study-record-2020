#include <stdio.h>
#define SQUARE(X) X *X
#define PR(X) printf("The result is %d.\n", X)
int main(void)
{
    int x = 5, z;

    printf("x=%d\n", x);
    z = SQUARE(x);
    printf("Evaluating SQARE(X): ");
    PR(z);
    z = SQUARE(2);
    printf("Evaluating SQARE(Z): ");
    PR(z);
    printf("Evaluating SQARE(x+2): ");
    PR(SQUARE(x + 2));
    //被换成了X+2*X+2， 即5+2*5+2=17
    printf("Evaluating 100/SQARE(2): ");
    PR(100 / SQUARE(2));

    printf("X is %d.\n", x);
    printf("Evaluating SQARE(++x): ");
    PR(SQUARE(++x));
    printf("after incrementing, x is %x.\n", x);

    return 0;
}