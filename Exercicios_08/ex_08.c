#include <stdio.h>
#include <stdlib.h>

int *allocVet(int n, int elem)
{

    int *vet = NULL;

    if (elem <= 0)
        return vet;
    else
    {
        vet = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
            vet[i] = elem;
        return vet;
    }
}

void main(void)
{
    int *allocVet(int, int);

    int *p = NULL, n, val;
    scanf("%d\n%d", &n, &val);

    p = allocVet(n, val);
    if (p != NULL)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", p[i]);
        }
    }

    else
    {
        printf("NULL");
    }
}
