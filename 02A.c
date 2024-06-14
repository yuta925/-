#include <stdio.h>

int bubbleSort(int A[], int N)
{
    int i, j, count = 0;
    for (i = 0; i < N; i++)
    {
        for (j = N - 1; j > i; j--)
        {
            if (A[j] < A[j - 1])
            {
                int t = A[j];
                A[j] = A[j - 1];
                A[j - 1] = t;
                count++;
            }
        }
    }
    return count;
}

int main(void)
{
    int i, A[100], N, count;
    while (1)
    {
        scanf("%d", &N);
        if (N >= 1 && N <= 100)
            break;
    }

    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);

    count = bubbleSort(A, N);

    for (i = 0; i < N; i++)
    {
        if (i > 0)
            printf(" ");
        printf("%d", A[i]);
    }

    printf("\n");
    printf("%d\n", count);

    return 0;
}