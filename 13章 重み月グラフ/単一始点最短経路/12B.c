#include <stdio.h>
#define MAX 100
#define INFTY (1 << 21)
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n;
int M[MAX][MAX];

void dijkstra()
{
    int minv;
    int d[MAX], color[MAX];

    for (int i = 0; i < n; i++)
    {
        d[i] = INFTY;
        color[i] = WHITE;
    }

    d[0] = 0;
    color[0] = GRAY;
    while (1)
    {
        minv = INFTY;
        int u = -1;
        for (int i = 0; i < n; i++)
        {
            if (minv > d[i] && color[i] != BLACK)
            {
                u = i;
                minv = d[i];
            }
        }
        if (u == -1)
            break;
        color[u] = BLACK;
        for (int v = 0; v < n; v++)
        {
            if (color[v] != BLACK && M[u][v] != INFTY)
            {
                if (d[v] > d[u] + M[u][v])
                {
                    d[v] = d[u] + M[u][v];
                    color[v] = GRAY;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", i, (d[i] == INFTY ? -1 : d[i]));
    }
}

int main(void)
{
    int i, j;
    scanf("%d", &n);

    // 初期化
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            M[i][j] = INFTY;
        }
    }

    // 隣接リストの読み取り
    for (i = 0; i < n; i++)
    {
        int u, k;
        while (scanf("%d", &u) != EOF)
        {
            scanf("%d", &k);
            for (j = 0; j < k; j++)
            {
                int v, w;
                scanf("%d %d", &v, &w);
                M[u][v] = w;
            }
        }
    }

    dijkstra();

    return 0;
}
