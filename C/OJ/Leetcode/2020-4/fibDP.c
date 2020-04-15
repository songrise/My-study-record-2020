int recur(long *dp, int N)
{
    if (N == 1)
    {
        return 0;
    }
    if (N == 2)
    {
        return 1;
    }
}

int fib(int N)
{
    static long dp[30] = {0};
    dp[1] = 1;
    if (N == 1)
    {
        return 0;
    }
    if (N == 2)
    {
        return 1;
    }
    return recur(N - 1) + recur(N - 2);
}
