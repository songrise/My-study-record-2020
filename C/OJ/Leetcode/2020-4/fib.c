int iter(int a, int b, int N)
{
    if (N == 0)
    {
        return b;
    }
    else
        return iter(b, a + b, N - 1);
}

int fib(int N)
{
    if (N < 2)
        return N;
    else
        return iter(1, 1, N - 2);
}