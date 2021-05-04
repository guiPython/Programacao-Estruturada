#include <stdio.h>
#include <stdlib.h>

void PrintVet(int vet[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
}

void Merge(int vet[], int aux[], int init, int end)
{
    int tam = (end - init + 1);
    int medIndex = (init + end) / 2;
    int initIndex = init;
    int endIndex = medIndex + 1;

    int auxIndex = init;

    while (initIndex <= medIndex && endIndex <= end)
    {
        if (vet[initIndex] <= vet[endIndex])
        {
            aux[auxIndex] = vet[initIndex++];
        }
        else
        {
            aux[auxIndex] = vet[endIndex++];
        }
        auxIndex++;
    }
    while (initIndex <= medIndex)
    {
        aux[auxIndex] = vet[initIndex++];
        auxIndex++;
    }

    while (endIndex <= end)
    {
        aux[auxIndex] = vet[endIndex++];
        auxIndex++;
    }
}

void MergeSort(int vet[], int aux[], int init, int end)
{
    if (init == end)
    {
        return;
    }

    int med = (init + end) / 2;
    MergeSort(vet, aux, init, med);
    MergeSort(vet, aux, med + 1, end);
    Merge(vet, aux, init, end);

    for (int i = init; i <= end; i++)
    {
        vet[i] = aux[i];
    }
}

void main(void)
{
    int n;
    scanf("%d", &n);

    int vet[n];
    int aux[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vet[i]);
    }

    MergeSort(vet, aux, 0, n - 1);
    PrintVet(aux, n);
}