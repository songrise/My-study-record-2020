#include <stdio.h>

int main(void)
{
    int matrix[3][3];
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("%d ", matrix[0][0] + matrix[1][1] + matrix[2][2]);
    printf("%d ", matrix[2][0] + matrix[1][1] + matrix[0][2]);

    return 0;
}