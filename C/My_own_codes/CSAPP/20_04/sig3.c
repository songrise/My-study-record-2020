#include<signal.h>
#include<stdio.h>
#include <unistd.h>

//typedef void (*sighandler_t)(int);
void handler(int signum)
{
    if(signum == SIGIO)
        printf("SIGIO   signal: %d\n", signum);
    else if(signum == SIGUSR1)
        printf("SIGUSR1   signal: %d\n", signum);
    else
        printf("error\n");
}

int main(void)
{
    //sighandler_t signal(int signum, sighandler_t handler);
    signal(SIGIO, handler);
    signal(SIGUSR1, handler);
    printf("%d  %d\n", SIGIO, SIGUSR1);
    while(1)
    {
        sleep(20);
    }
    return 0;
}
