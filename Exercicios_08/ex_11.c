#include <stdio.h>
#include <stdlib.h>

int *SomaVetores(int *v, int *w, int n)
{
    int *res = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        res[i] = v[i] + w[i];
    }
    return res;
}

void main(void)
{
    int *res, n;
    scanf("%d", &n);

    int v[n], w[n];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0)
            {
                scanf("%d", &v[j]);
            }

            if (i == 1)
            {
                scanf("%d", &w[j]);
            }
        }
    }

    res = SomaVetores(v, w, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", res[i]);
    }
}