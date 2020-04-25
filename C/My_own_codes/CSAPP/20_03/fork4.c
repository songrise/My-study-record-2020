#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
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
    int child_status;
    if (fork() == 0)
    {
        printf("HC: hello from child\n");
        exit(0);
    }
    else
    {
        printf("HP: hello from parent\n");
        wait(&child_status); //store into child_status.
        if (WIFEXITED(child_status))
            printf("CT: child has terminated, because wifexited\n");
    }
    printf("Bye\n");
    while (1)
        ;
}