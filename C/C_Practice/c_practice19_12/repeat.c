#include <stdio.h>

int main(int argc, char *argv[])
// 命令行参数
{
    int count;

    printf("The cmd has %d arguments:\n", argc - 1);
    for (count = 1; count < argc; count++)
        printf("%d: %s\n", count, argv[count]);
    printf("\n");

    return 0;
}