#include <stdio.h>
#define LEN 7

int test1(int *A, int N)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += A[i / 3];
    for (int i = 0; i < N; i++)
        sum += A[(i / 3) + 2];
    for (int i = 0; i < N; i++)
        sum += A[(i / 3) + 1];
    return sum;
}

// int test(int *A, int N)
// {
//     int sum = 0;
//     for (int i = 0; i < N; i++)
//     {
//         sum += A[i / 3];
//         sum += A[(i / 3) + 1];
//         sum += A[(i / 3) + 2];
//     }
//     return sum;
// }

int test2(int *A, int N)
{
    //of median locality.l
    int sum = 0;
    int i;
    for (i = 0; i < (N / 3); i++)
    {
        sum += (A[i]) * 3;
        sum += (A[i + 1]) * 3;
        sum += (A[i + 2]) * 3;
    }
    int reminder = N % 3;
    sum += (A[i]) * reminder;
    sum += (A[i + 1]) * reminder;
    sum += (A[i + 2]) * reminder;

    return sum;
}

int test3(int *A, int N)
{
    int sum = 0;
    int reminder = N % 3;

    for (int i = 0; i < (N / 3) + 3; i++)
    {
        int factor = 3;

        if (1 == i)
        {
            factor += 3;
        }
        else if (i > 1)
        {
            factor += 6;
        }
        if (i >= N / 3)
        {
            factor -= (i - N / 3) * 3;
            factor -= (3 - reminder);
        }
        sum += (A[i]) * factor; //NOTICE here, array is referenced sequentially, so good spatial locality.
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    printf("%d, %d, %d", test1(A, LEN), test2(A, LEN), test3(A, LEN));
    return 0;
}
