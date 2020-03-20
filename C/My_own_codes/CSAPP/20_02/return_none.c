#include <stdio.h>
void cond(long, long *);

int main(int argc, char const *argv[])
{
    long a = 9;
    long n = 3;
    cond(a, &n);
    return 0;
}

void cond(long a, long *p)
{
    if (!p)
        goto done;
    if (*p >= a)
        goto done;
    else
        *p = a;
done:
    return;
}