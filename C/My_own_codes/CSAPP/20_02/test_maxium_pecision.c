#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a = 0X7fffffff;
    float b = (float)a;
    int c = b;

    printf("%x\n", a);
    printf("%x", c);

    return 0;
}
