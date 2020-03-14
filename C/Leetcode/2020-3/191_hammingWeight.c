//result Time 100%, Memory 100%

#include <stdio.h>
int hammingWeight(int n)
{
    int count = 0;
    while (n)
    {
        if (n & 1)
            count++;
        n >>= 1;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    printf("The hW for %d is %d", 31, hammingWeight(31));
    return 0;
}
