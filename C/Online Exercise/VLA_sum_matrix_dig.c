#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int matrix[n][n];
    int i, j, dig1, dig2;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (dig1 = 0, dig2=0, i = 0; i < n; i++)
    {   dig1 += matrix[i][i];
        dig2 += matrix[i][n - i - 1];
    }
    
    printf("%d",(n % 2)? (dig1 + dig2 - matrix[n/2][n/2]):(dig1 + dig2)); 
    return 0;
}