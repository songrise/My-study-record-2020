#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void handler(int signum)
{
    if (signum == SIGCHLD)
        printf("SIGCHLD   signal: %d\n", signum);
    else
        printf("error\n");
}

int main()
{
    signal(SIGCHLD, handler);
    if (fork() == 0)
    {
        /* Child */
        printf("Terminating Child, PID = %d\n", getpid());
        exit(0);
    }
    else
    {
        printf("Running Parent, PID = %d\n", getpid());
        while (1)
            ; /* Infinite loop */
    }
}