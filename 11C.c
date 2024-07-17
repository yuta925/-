#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 100
#define INFTY (1 << 21)

int n, M[N][N];
int d[N];

// キューの実装
int queue[N];
int head = 0, tail = 0;

void enqueue(int x)
{
    queue[tail] = x;
    tail = (tail + 1) % N;
}

int dequeue()
{
    int x = queue[head];
    head = (head + 1) % N;
    return x;
}

int is_empty()
{
    return head == tail;
}

void bfs(int s)
{
    enqueue(s);
    for (int i = 0; i < n; i++)
        d[i] = INFTY;
    d[s] = 0;
    int u;
    while (!is_empty())
    {
        u = dequeue();
        for (int v = 0; v < n; v++)
        {
            if (M[u][v] == 0)
                continue;
            if (d[v] != INFTY)
                continue;
            d[v] = d[u] + 1;
            enqueue(v);
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", i + 1, ((d[i] == INFTY) ? -1 : d[i]));
    }
}

int main()
{
    int u, k, v;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            M[i][j] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &u, &k);
        u--;
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &v);
            v--;
            M[u][v] = 1;
        }
    }

    bfs(0);

    return 0;
}
