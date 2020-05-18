#include <iostream>

using namespace std;
int fib(int N)
{
    if (N <= 2)
        return 1;
    else
        return fib(N - 1) + fib(N - 2);
}

int main(int argc, char const *argv[])
{
    cout << fib(9);
    return 0;
}



// int fib(int N)
// {
//     if (N <= 2)
//     {
//         return 1;
//     }

//     int dp[N] = {0};
//     dp[0] = 1;
//     dp[1] = 1;
//     for (size_t i = 0; i < N; i++)
//     {
//         dp[i] = dp[i - 1] + dp[i - 2];
//     }
//     return dp[N];
// }