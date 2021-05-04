#include <stdio.h>

int Part(int V[], int i, int f)
{
    int esq, dir, p, aux;
    esq = i;
    dir = f;
    p = V[i];

    while (esq < dir)
    {
        while (V[esq] >= p)
        {
            esq++;
        }
        while (V[dir] < p)
        {
            dir--;
        }
        if (esq < dir)
        {
            aux = V[esq];
            V[esq] = V[dir];
            V[dir] = aux;
        }
    }
    V[i] = V[dir];
    V[dir] = p;
    return dir;
}

void QuickSortInv(int V[], int i, int f)
{
    int p = 0;
    if (f > i)
    {
        p = Part(V, i, f);
        QuickSortInv(V, i, p - 1);
        QuickSortInv(V, p + 1, f);
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

    QuickSortInv(vet, 0, n - 1);
    PrintVet(vet, n);
}
