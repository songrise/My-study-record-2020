#include <stdio.h>
#include<stdlib.h>

int main(void)
{
    int * pt;
    pt = (int *) malloc(200000*sizeof(float));
    getchar();
    free(pt);

    return 0;
}