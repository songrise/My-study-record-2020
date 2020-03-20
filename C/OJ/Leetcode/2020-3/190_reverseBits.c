//result Time 68%, Memory 100%
#include <stdio.h>

int reverseBits(int n)
{
    int ans = 0, pow = 31;
    while (n)
    {
        ans += ((n & 1) << pow--);
        n >>= 1;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    printf("The reversed for ;");
    return 0;
}
