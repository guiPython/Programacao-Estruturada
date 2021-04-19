#include <stdio.h>

int *InsertionSortInv(int vet[], int n)
{
    int elemt, j;
    for (int i = 0; i < n; i++)
    {
        elemt = vet[i];
        int j = i;
        while (j > 0 && elemt > vet[j - 1])
        {
            vet[j] = vet[j - 1];
            j--;
        }
        vet[j] = elemt;
    }
    return vet;
}

void PrintVet(int vet[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
}

void main(void)
{
    int n;
    scanf("%d", &n);
    int vet[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vet[i]);
    }

    vet[n] = InsertionSortInv(vet, n);
    PrintVet(vet, n);
}