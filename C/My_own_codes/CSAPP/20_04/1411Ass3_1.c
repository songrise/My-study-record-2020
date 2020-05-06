
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <wait.h>

int main()
{
    int a = 0;
    if (fork() == 0)
    {
        a = a + 3;
        if (fork() == 0)
        {
            a = a + 9;
            printf("Lv: %d\n", a);
            if (fork() == 0)
                a = a + 27;
        }
    }
    printf("Lw: %d\n", a);

    return 0;
}
