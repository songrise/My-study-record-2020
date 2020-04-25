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
    
    if (fork() == 0)
    {
        /* Child */
        printf("Running Child, PID = %d\n",
               getpid());
        while (1)
            ; /* Infinite loop */
    }
    else
    {
        printf("Terminating Parent, PID = %d\n",
               getpid());
        exit(0);
    }
}