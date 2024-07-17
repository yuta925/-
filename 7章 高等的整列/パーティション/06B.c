#include <stdio.h>
#define MAX 100000

int n, A[MAX];

void partation(int p, int r)
{
    // j は分ける境目
    int i, j = p - 1, x = A[r], tmp;
    for (i = p; i < r; i++)
    {
        if (A[i] <= x)
        {
            tmp = A[++j];
            A[j] = A[i];
            A[i] = tmp;
        }
    }

    // 最後の要素を入れ替える
    tmp = A[++j];
    A[j] = A[r];
    A[r] = tmp;

    for (i = 0; i < n; i++)
    {
        if (i > 0)
            printf(" ");
        if (i == j)
            printf("[%d]", A[i]);
        else
            printf("%d", A[i]);
    }
    printf("\n");
}

int main(void)
{
    int i;
    while (1)
    {
        scanf("%d", &n);
        if (n >= 1 && n <= MAX)
            break;
    }

    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    partation(0, n - 1);
}
