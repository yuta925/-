#include <stdio.h>
#define Max 200000

int L[Max / 2 + 2], R[Max / 2 + 2];

long long merge(int A[], int n, int left, int mid, int right)
{
    int i, j, k;
    long long cnt = 0;
    int n1 = mid - left;
    int n2 = right - mid;
    for (i = 0; i < n1; i++)
        L[i] = A[left + i];
    for (i = 0; i < n2; i++)
        R[i] = A[mid + i];
    L[n1] = R[n2] = 2000000000;
    i = j = 0;
    for (k = left; k < right; k++)
    {
        if (L[i] <= R[j])
            A[k] = L[i++];
        else
        {
            A[k] = R[j++];
            cnt += n1 - i;
        }
    }
    return cnt;
}

long long mergeSort(int A[], int n, int left, int right)
{
    int mid;
    long long v1, v2, v3;
    if (left + 1 < right)
    {
        mid = (left + right) / 2;
        v1 = mergeSort(A, n, left, mid);
        v2 = mergeSort(A, n, mid, right);
        v3 = merge(A, n, left, mid, right);
        return v1 + v2 + v3;
    }
    else
        return 0;
}

int main(void)
{
    int A[Max], n, i;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    long long ans = mergeSort(A, n, 0, n);
    printf("%lld\n", ans);
    
    return 0;
}