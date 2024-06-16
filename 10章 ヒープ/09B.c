#include <stdio.h>
#define MAX 2000000

int H, A[MAX + 1];

void MaxHeapify(int i)
{
    int l, r, largest;
    l = 2 * i;
    r = 2 * i + 1;

    // 左の子、自分、右の子で値が最大のノードを選ぶ
    if (l <= H && A[l] > A[i])
        largest = l;
    else
        largest = i;

    if (r <= H && A[r] > A[largest])
        largest = r;

    if (largest != i)
    {
        int tmp = A[i];
        A[i] = A[largest];
        A[largest] = tmp;
        MaxHeapify(largest);
    }
}

int main(void)
{
    while (1)
    {
        scanf("%d", &H);
        if (H <= 500000)
            break;
    }
    for (int i = 1; i <= H; i++)
        scanf("%d", &A[i]);

    for (int i = H / 2; i >= 1; i--)
        MaxHeapify(i);

    for (int i = 1; i <= H; i++)
        printf(" %d", A[i]);
    printf("\n");

    return 0;
}
