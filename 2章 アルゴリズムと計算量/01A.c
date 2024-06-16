#include <stdio.h>

void trace(int A[], int N)
{
    for (int i = 0; i < N - 1; i++)
        printf("%d ", A[i]);
    printf("%d\n", A[N - 1]);
}

void insertion_sort(int A[], int N)
{
    for (int i = 1; i < N; i++)
    {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v)
        {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = v;
        trace(A, N);
    }
}

int main(void)
{
    int N;
    int A[100];
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    trace(A, N);
    insertion_sort(A, N);

    return 0;
}