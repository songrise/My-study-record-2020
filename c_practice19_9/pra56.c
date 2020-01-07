#include <stdio.h>

int main(void)
{
    const int line=4;
    const int p=7;
    int n;
    int i;
    
    for(i=1;i<=line;i++)
    {
        for(n=1;n<=p;n++)
        printf("$");

    printf("\n");
    }

    return 0;
}