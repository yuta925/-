#include <stdio.h>

typedef struct Card
{
    char suit;
    int value;
} Card;

void bubbleSort(Card A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = N - 1; j > i; j--)
        {
            if (A[j].value < A[j - 1].value)
            {
                Card t = A[j];
                A[j] = A[j - 1];
                A[j - 1] = t;
            }
        }
    }
}

void selectionSort(Card A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        int min = i;
        for (int j = i; j < N; j++)
            if (A[min].value > A[j].value)
                min = j;
        Card t = A[i];
        A[i] = A[min];
        A[min] = t;
    }
}

void print(Card A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        if (i > 0)
            printf(" ");
        printf("%c%d", A[i].suit, A[i].value);
    }
    printf("\n");
}

int isStable(Card C1[], Card C2[], int N)
{
    for (int i = 0; i < N; i++)
        if (C1[i].suit != C2[i].suit)
            return 0;
    return 1;
}

int main(void)
{
    int N;
    Card C1[100], C2[100];
    char ch;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf(" %c%d", &C1[i].suit, &C1[i].value);
        C2[i] = C1[i];
    }

    bubbleSort(C1, N);
    selectionSort(C2, N);

    print(C1, N);
    printf("Stable\n");
    print(C2, N);
    if (isStable(C1, C2, N))
        printf("Stable\n");
    else
        printf("Not stable\n");

    return 0;
}