#include <stdio.h>
#include <math.h>
#define MAX 2097150 // 2^21 - 1
#define NIL -1

typedef struct
{
    int p, left, right;
} Node;

Node T[MAX];
int n, D[MAX];

void print(int u)
{
    int i, c;
    printf("node %d: ", u);
    printf("parent = %d, ", T[u].p);
    printf("depth = %d, ", D[u]);

    if (T[u].p == NIL)
        printf("root, ");
    else if (T[u].left == NIL)
        printf("leaf, ");
    else
        printf("internal node, ");

    printf("[");
    for (i = 0, c = T[u].left; c != NIL; i++, c = T[c].right)
    {
        if (i)
            printf(", ");
        printf("%d", c);
    }
    printf("]\n");
}

// 再起的に深さを求める
void rec(int u, int p)
{
    D[u] = p;
    if (T[u].right != NIL)
        rec(T[u].right, p);
    if (T[u].left != NIL)
        rec(T[u].left, p + 1);
}

int main(void)
{
    int i, j, d, v, c, l, r;
    while (1)
    {
        scanf("%d", &n);
        if (n >= 1 && n <= 100000)
            break;
    }

    // 木の初期化
    for (i = 0; i < n; i++)
        T[i].p = T[i].left = T[i].right = NIL;

    // 木の構築
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &v, &d);
        for (j = 0; j < d; j++)
        {
            scanf("%d", &c);
            if (j == 0)
                T[v].left = c;
            else
                T[l].right = c;
            l = c;
            T[l].p = v;
        }
    }

    // r:
    for (i = 0; i < n; i++)
        if (T[i].p == NIL)
            r = i;

    // 深さの計算
    rec(r, 0);

    // 各節点iの節点番号、親の節点番号、深さ、節点の種類、子のリストを出力
    for (i = 0; i < n; i++)
        print(i);

    return 0;
}