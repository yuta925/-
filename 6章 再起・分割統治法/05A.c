#include <stdio.h>

int n, A[50];

int solve(int i, int m)
{
    if (m == 0)
        return 1;
    if (i >= n)
        return 0;
    int res = solve(i + 1, m) || solve(i + 1, m - A[i]);
    return res;
}

int main(void)
{
    int q, M, i;

    while (1)
    {
        scanf("%d", &n);
        if (n <= 20)
            break;
    }
    for (i = 0; i < n; i++)
    {
        while (1)
        {
            scanf("%d", &A[i]);
            if (A[i] >= 1 && A[i] <= 2000)
                break;
        }
    }
    while (1)
    {
        scanf("%d", &q);
        if (q <= 200)
            break;
    }
    for (i = 0; i < q; i++)
    {
        while (1)
        {
            scanf("%d", &M);
            if (M >= 1 && M <= 2000)
                break;
        }
        if (solve(0, M))
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}