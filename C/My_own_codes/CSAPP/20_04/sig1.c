#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int x = 0;

void handle_sigint(int sig)
{
    x++;
    printf("Caught signal %d\n", sig);
}

int main()
{
    x = 0;
    signal(SIGINT, handle_sigint);
    while (1)
    {
        printf("hello world: %d\n", x);
        sleep(1);
    }
    return 0;
}
