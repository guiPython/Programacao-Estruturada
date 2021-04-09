#include <stdio.h>
#include <stdlib.h>

int *VetorSumColMatriz(int m[3][3])
{
    int *vet = malloc(3 * sizeof(int));
    for (int i = 0; i < 3; i++)
    {
        vet[i] = 0;
        for (int j = 0; j < 3; j++)
        {
            vet[i] += m[j][i];
        }
    }
    return vet;
}

void main(void)
{
    int *vet = NULL, m[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }

    vet = VetorSumColMatriz(m);

    for (int i = 0; i < 3; i++)
    {
        printf("%d ", vet[i]);
    }
}
