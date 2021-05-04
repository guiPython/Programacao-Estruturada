
#include <stdio.h>

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Quicksort(int vet[], int init, int end)
{
    if (init < end)
    {
        int pivo = init;
        for (int i = init + 1; i < end; i++)
        {
            if (vet[i] < vet[init])
            {
                Swap(&vet[i], &vet[++pivo]);
            }
        }
        Swap(&vet[init], &vet[pivo]);
        Quicksort(vet, init, pivo);
        Quicksort(vet, pivo + 1, end);
    }
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

    Quicksort(vet, 0, n);
    PrintVet(vet, n);
}