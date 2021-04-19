#include <stdbool.h>
#include <stdio.h>

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSortInv(int vet[], int n)
{
    bool aux;
    do
    {
        aux = false;
        for (int i = 0; i < n - 1; i++)
        {
            if (vet[i] < vet[i + 1] * 1)
            {
                Swap(&vet[i + 1], &vet[i]);
                aux = true;
            }
        }
        n--;
    } while (aux != false);
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

    BubbleSortInv(vet, n);
    PrintVet(vet, n);
}