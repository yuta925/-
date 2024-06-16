#include <stdio.h>
#include <stdlib.h>

long long cnt;
int l;
int A[1000000];
int n;
int G[1000];    // 十分なサイズの配列を使用
int G_size = 0; // Gの要素数を追跡するための変数

// 間隔g を指定した挿入ソート
void insertionSort(int A[], int n, int g)
{
    for (int i = g; i < n; i++)
    {
        int v = A[i];
        int j = i - g;
        while (j >= 0 && A[j] > v)
        {
            A[j + g] = A[j];
            j -= g;
            cnt++;
        }
        A[j + g] = v;
    }
}

void shellSort(int A[], int n)
{
    // 数列G = {1, 4, 13, 40, 121, 364, 1093, ...} を生成
    int h = 1;
    while (1)
    {
        if (h > n)
            break;
        G[G_size++] = h;
        h = 3 * h + 1;
    }

    for (int i = G_size - 1; i >= 0; i--)
    { // 逆順にG[i] = g を指定
        insertionSort(A, n, G[i]);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    cnt = 0;

    shellSort(A, n);

    printf("%d\n", G_size);
    for (int i = G_size - 1; i >= 0; i--)
    {
        printf("%d", G[i]);
        if (i > 0)
            printf(" ");
    }
    printf("\n");
    printf("%lld\n", cnt); // cntはlong longなので%lldを使用
    for (int i = 0; i < n; i++)
        printf("%d\n", A[i]);
    return 0;
}
