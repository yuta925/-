#include <stdio.h>

int linearSearch(int n, int key, int A[])
{
    int i = 0;
    A[n] = key;
    while (A[i] != key)
        i++;
    return i != n;
}

int main(void)
{
    int i, n, A[10000 + 1], q, key, sum = 0;

    while (1)
        if (scanf("%d", &n) <= 10000)
            break;

    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    while (1)
        if (scanf("%d", &q) <= 500)
            break;

    for (i = 0; i < q; i++)
    {
        scanf("%d", &key);
        if (linearSearch(n, key, A))
            sum++;
    }
    printf("%d\n", sum);

    return 0;
}