int F(int *A, int L)
{
    int temp = A[0];
    for (int i = 0; i < L; i++)
        if (A[i] > temp)
            temp = A[i];
    return temp;
}

int main()
{
}