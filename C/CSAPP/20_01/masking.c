#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num = 0b00001101; //num == 13.
    int mask = 0b11110000;
    printf("%d\n", num);
    printf("%d\n", num & mask);
    //因为num 和 mask 都遵循同一种端序，所以结果仍然如期望。

    return 0;
}
