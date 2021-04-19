#include <stdio.h>

void PrintVet(int *vet, int n)
{
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", vet[i]);
    }
}

void InsertionSort(int *vet, int n)
{
    int elemnt = vet[n], j = n;
    while (j > 0 && elemnt < vet[j - 1])
    {
        vet[j] = vet[j - 1];
        j--;
    }
    vet[j] = elemnt;
}

void main(void)
{
    int n;
    scanf("%d", &n);
    int vet[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vet[i]);
        InsertionSort(vet, i);
        PrintVet(vet, i);
        printf("\n");
    }
}