#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void main()
{
    int a = 1;
    fork();
    a = a + 2;
    if (fork() == 0)
        a = a * 3;
    printf("La: %d\n", a);
}
