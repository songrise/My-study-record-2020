int iter(int a, int b, int N)
{
    return iter(b, a + b, N - 1)
}

int fib(int N)
{
    return iter(1, 1, N);
}