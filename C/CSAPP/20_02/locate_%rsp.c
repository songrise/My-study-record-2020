#include <stdio.h>
int main(int argc, char const *argv[])
{
    long local;
    printf("local at %p\n", &local);
    getchar();
    return 0;
}
