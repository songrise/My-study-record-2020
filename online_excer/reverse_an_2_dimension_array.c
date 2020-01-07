#include <stdio.h>

void reverse(int matrix[][3]);

int main(void)
{
    int i, j;
    int matrix[3][3];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }
    return 0;
}

