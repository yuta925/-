#include <stdio.h>
#define MAX 100

int main(void)
{
    int n, A[MAX][MAX], u, k, v;
    int i, j;
    while (1)
    {
        scanf("%d", &n);
        if (n >= 0 && n <= 100)
            break;
    }

    for (i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = 0;

    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &u, &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &v);
            A[u - 1][v - 1] = 1;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (j != n - 1)
                printf("%d ", A[i][j]);
            else
                printf("%d\n", A[i][j]);
    }
}