//compile in linux
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int x = 1;
    if (fork() == 0)
    {
        printf("p1:x=%d\n", ++x);
    }
    printf("p2:x=%d\n", --x);
    exit(0);
}
