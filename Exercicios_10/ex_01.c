#include <stdio.h>
#include <stdlib.h>

void PrintVet(int vet[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
}

void Merge(int v[], int init, int m, int f)
{
    int *temp = NULL, n1, n2, tam, i, j, k;
    int f1 = 0, f2 = 0;

    tam = f - init + 1;
    n1 = init;
    n2 = m + 1;
    temp = (int *)malloc(tam * sizeof(int));

    if (temp != NULL)
    {
        for (i = 0; i < tam; i++)
        {
            if (!f1 && !f2)
            {
                if (v[n1] > v[n2])
                {
                    temp[i] = v[n1++];
                }
                else
                {
                    temp[i] = v[n2++];
                }
                if (n1 > m)
                {
                    f1 = 1;
                }
                if (n2 > f)
                {
                    f2 = 1;
                }
            }
            else
            {
                if (!f1)
                {
                    temp[i] = v[n1++];
                }
                else
                {
                    temp[i] = v[n2++];
                }
            }
        }
    }
    k = init;
    for (j = 0; j < tam; j++)
    {
        v[k] = temp[j];
        k++;
    }
    free(temp);
}

void MergeSort(int v[], int init, int f)
{
    int m = 0;
    if (init < f)
    {
        m = (init + f) / 2;
        MergeSort(v, init, m);
        MergeSort(v, m + 1, f);
        Merge(v, init, m, f);
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

    MergeSort(vet, 0, n - 1);
    PrintVet(vet, n);
}