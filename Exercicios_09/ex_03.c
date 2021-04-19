#include <stdio.h>

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSortInv(int vet[], int n)
{
    int aux;
    for (int i = 0; i < n - 1; i++)
    {
        aux = i;
        for (int j = i + 1; j < n; j++)
        {
            if (vet[j] > vet[aux])
            {
                aux = j;
            }
        }

        if (aux != i)
        {
            Swap(&vet[i], &vet[aux]);
        }
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

    SelectionSortInv(vet, n);
    PrintVet(vet, n);
}