//compile in linux
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    if (fork() == 0)
    {
        printf("Terminating Child, PID = %d\n", getpid());
        exit(0);
    }
    else
    {
        printf("Running Parent, PID = %d\n", getpid());
    }
    while (1)
        ;
    return 0;
}
