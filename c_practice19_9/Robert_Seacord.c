#include <stdio.h>
#define cnt 10

int main(void)
{
    unsigned i;
    for (i=cnt-1; i<cnt;i--)//overflow
    {
        printf("its %d th iteration\n",i);
    }
    return 0;

}