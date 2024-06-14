#include <stdio.h>

int selectionSort(int A[], int N)
{
    int i, j, count = 0, min, t;
    for (i = 0; i < N - 1; i++)
    {
        min = i;
        for (j = i; j < N; j++)
            if (A[min] > A[j])
                min = j;
        t = A[i];
        A[i] = A[min];
        A[min] = t;
        if (i != min)
            count++;
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

    count = selectionSort(A, N);

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