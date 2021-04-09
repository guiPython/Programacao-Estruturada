#include <stdio.h>
#include <stdlib.h>

int **allocMatrizIdentitade(int n)
{
    int **m = (int **)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        m[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                m[i][j] = 0;
            }

            else if (i > j)
            {
                m[i][j] = -1;
            }

            else
            {
                m[i][j] = 1;
            }
        }
    }

    return m;
}

void main(void)
{
    int **m, n;
    scanf("%d", &n);

    m = allocMatrizIdentitade(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}