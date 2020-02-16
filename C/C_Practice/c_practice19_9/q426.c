#include <stdio.h>
#define d "im"

int main(void)
{
    char s[20];
    printf("enter a strin plz: ");
    scanf("%d", s);
    printf("\nyou entered %c,which is %d long\n", s, sizeof(s));
    printf("%s has %d letters", d, sizeof(d));

    return 0;
}