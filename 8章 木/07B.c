#include <stdio.h>
#include <math.h>

#define MAX 100000
#define NIL -1

typedef struct
{
    int parent, left, right, deg;
} Node;

/**
 * T[]: 各節点を格納する配列
 * n: 節点の数
 * D[]: 深さを格納する配列
 * S[]: 兄弟を格納する配列
 * Deg[]: 次数を格納する配列
 * H[]: 高さを格納する配列
 */
Node T[MAX];
int n, D[MAX], S[MAX], H[MAX];

void print(int u)
{
    int i, c;
    printf("node %d: ", u);
    printf("parent = %d, ", T[u].parent);
    printf("sibling = %d, ", S[u]);
    int deg = 0;
    if (T[u].left != NIL)
        deg++;
    if (T[u].right != NIL)
        deg++;
    printf("degree = %d, ", deg);
    printf("depth = %d, ", D[u]);
    printf("height = %d, ", H[u]);
    if (T[u].parent == NIL)
        printf("root\n");
    else if (T[u].left == NIL && T[u].right == NIL)
        printf("leaf\n");
    else
        printf("internal node\n");
}

// 深さを求める
void setDepth(int u, int d)
{
    if (u == NIL)
        return;
    D[u] = d;
    setDepth(T[u].left, d + 1);
    setDepth(T[u].right, d + 1);
}

// 高さを求める
int setHeight(int u)
{
    int h1 = 0, h2 = 0;
    if (T[u].left != NIL)
        h1 = setHeight(T[u].left) + 1;
    if (T[u].right != NIL)
        h2 = setHeight(T[u].right) + 1;
    return H[u] = (h1 > h2 ? h1 : h2);
}

int main(void)
{
    /**
     * i, j: カウンタ変数
     * n: 節点の数
     * v: 節点の番号
     * l: 左の子の番号
     * r: 右の子の番号
     */
    int i, j, n, v, l, r, root;
    while (1)
    {
        scanf("%d", &n);
        if (n >= 1 && n <= 25)
            break;
    }

    // 初期化
    for (i = 0; i < n; i++)
    {
        T[i].parent = NIL;
        S[i] = NIL;
    }

    // 節点の情報を格納
    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d", &v, &l, &r);
        T[v].left = l;
        T[v].right = r;
        if (l != NIL)
            T[l].parent = v;
        if (r != NIL)
            T[r].parent = v;
    }

    // 兄弟の情報を格納
    for (i = 0; i < n; i++)
    {
        if (T[i].left != NIL && T[i].right != NIL)
        {
            S[T[i].left] = T[i].right;
            S[T[i].right] = T[i].left;
        }
    }

    for (i = 0; i < n; i++)
        if (T[i].parent == NIL)
            root = i;

    // 接点の深さを求める
    setDepth(root, 0);
    // 接点の高さを求める
    setHeight(root);

    for (i = 0; i < n; i++)
        print(i);

    return 0;
}