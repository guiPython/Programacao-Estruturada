#include <stdio.h>
void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int IndexOfMinimum(int vet[], int n, int i)
{
    int aux = i;
    for (int j = i + 1; j < n; j++)
    {
        if (vet[j] < vet[aux])
        {
            aux = j;
        }
    }
    return aux;
}

void SelectionSort(int vet[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int indexOfMinimum = IndexOfMinimum(vet, n, i);
        if (indexOfMinimum != i)
        {
            Swap(&vet[i], &vet[indexOfMinimum]);
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
    int elemnt;
    scanf("%d", &elemnt);

    int n;
    scanf("%d", &n);
    n++;

    int vet[n];
    vet[n - 1] = elemnt;

    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d", &vet[i]);
    }

    SelectionSort(vet, n);
    PrintVet(vet, n);
}