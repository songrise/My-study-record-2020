#define MSG "I'm special"
#include <stdio.h>

int main(void)
{
    char ar[] = MSG;
    const char *pt = MSG;
    printf ("address of \"I'm special\": %p \n", "I'm special");
    printf("address of ar: %p\n", ar);
    printf("address of pt: %p\n", pt);
    printf("address of MSG: %p\n", MSG);
    printf ("address of \"I'm special\": %p \n", "I'm special");

    return 0;
}