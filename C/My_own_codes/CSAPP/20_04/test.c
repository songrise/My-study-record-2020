#include <stdio.h>
#include <stdint.h>

int main(int argc, char const *argv[])
{
    uint64_t X[100];
    printf("F: %p, S: %p, T: %p", X, &X[25], &X[78]);
    return 0;
}
