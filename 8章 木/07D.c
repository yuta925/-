#include <stdio.h>
#include <stdlib.h>

int n, pos, post_pos;
int *pre, *in, *post;

void rec(int l, int r)
{
    if (l >= r)
        return;
    int root = pre[pos++];
    printf("root: %d\n", root);
    int i, m;
    for (i = l; i < r; i++)
        if (in[i] == root)
            m = i;
    printf("m: %d\n", m);
    rec(l, m);
    rec(m + 1, r);
    printf("post_pos: %d, root: %d\n", post_pos, root);
    post[post_pos++] = root;
}

void solve()
{
    pos = 0;
    post_pos = 0;
    rec(0, n);
    for (int i = 0; i < n; i++)
    {
        if (i)
            printf(" ");
        printf("%d", post[i]);
    }
    printf("\n");
}

int main()
{
    int i;
    scanf("%d", &n);

    pre = (int *)malloc(n * sizeof(int));
    in = (int *)malloc(n * sizeof(int));
    post = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
        scanf("%d", &pre[i]);

    for (i = 0; i < n; i++)
        scanf("%d", &in[i]);

    for (i = 0; i < n; i++)
        post[i] = 0;

    solve();

    free(pre);
    free(in);
    free(post);

    return 0;
}
