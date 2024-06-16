#include <stdio.h>

int n, A[100000];

int binarySearch(int key)
{
    int left = 0;
    int right = n;
    int mid;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (A[mid] < key)
            left = mid + 1;
        else if (A[mid] > key)
            right = mid;
        else
            return 1;
    }
    return 0;
}

int main(void)
{
    int i, q, k, sum = 0;

    while (1)
        if (scanf("%d", &n) <= 100000)
            break;
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    while (1)
        if (scanf("%d", &q) <= 50000)
            break;
    for (i = 0; i < q; i++)
    {
        scanf("%d", &k);
        if (binarySearch(k))
            sum++;
    }
    printf("%d\n", sum);

    return 0;
}