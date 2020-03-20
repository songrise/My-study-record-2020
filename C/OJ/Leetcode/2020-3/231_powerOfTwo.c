//result Time 4ms 70.87%, Memory 5.3mb 100%

bool isPowerOfTwo(int n)
{
    bool ans;
    //avoid unpredictable condition statement(if n > 0) to speed up.
    while (!(n & 1) && n)
        n >>= 1;

    ans = ((!(n >> 1)) && (n > 0));
    return ans;
}

//another version Time 4ms 70.87%, Memory 5.3mb 100%
bool isPowerOfTwo2(int n)
{
    if (n <= 0)
        return 0;
    while (!(n & 1))
        n >>= 1;

    return (!(n >> 1));
}
//This should be the best version.
bool isPowerOfTwo3(int n)
{
    if (n > 0)
    {
        return ((x & (x - 1)) == 0);
    }
    return 0;
}