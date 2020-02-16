//defines.c
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    printf("bigget int %d\n",INT_MAX);
    printf("smallest long long%lld\n",LLONG_MIN);
    printf("one byte= %d bits\n",CHAR_BIT);
    printf("float precision= %d digits\n",__FLT_DIG__);

    return 0;
}