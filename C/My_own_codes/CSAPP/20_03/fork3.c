#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t pid = fork();
    if (pid == 0)
    {
        printf("child process \n ");
    }
    else
    {
        printf("child process with pid = %d\n", pid);
        printf("parent process.\n");
        pid_t grppid = getpgrp();
        printf("group pid = %d", grppid);
    }

    while (1)
    {
        ; /* code */
    }

    return 0;
}
