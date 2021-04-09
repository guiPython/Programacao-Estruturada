#include <stdio.h>
#include <stdlib.h>

int *MultVetorMatriz(int m[3][3], int *vet)
{
    int *v = malloc(3 * sizeof(int));
    for (int i = 0; i < 3; i++)
    {
        v[i] = 0;
        for (int j = 0; j < 3; j++)
        {
            v[i] += vet[j] * m[i][j];
        }
    }
    return v;
}

void main(void)
{
    int *vet = NULL, m[3][3], v[3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &v[i]);
    }

    vet = MultVetorMatriz(m, v);

    for (int i = 0; i < 3; i++)
    {
        printf("%d ", vet[i]);
    }
}