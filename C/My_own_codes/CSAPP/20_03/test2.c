#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <wait.h>

int main()
{
    int a = 0;
    printf("Lx: %d\n", a);
    if (fork() == 0)
        a = a + 1;
    printf("Ly: %d\n", a);
    if (fork() == 0)
        a = a + 2;
    printf("Lz: %d\n", a);
}
