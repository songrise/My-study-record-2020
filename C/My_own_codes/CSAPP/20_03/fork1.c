//compile in linux
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    fork();
    fork();
    printf("hello!\n");
    exit(0);
}
