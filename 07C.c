#include <stdio.h>
#define MAX 100000
#define NIL -1

typedef struct
{
    int parent, left, right;
} Node;

int Pre[MAX], In[MAX], Post[MAX], p[MAX];
Node T[MAX];

void preOrder(int u)
{
    if (u == NIL)
        return;
    printf(" %d", u);
    preOrder(T[u].left);
    preOrder(T[u].right);
}

void inOrder(int u)
{
    if (u == NIL)
        return;
    inOrder(T[u].left);
    printf(" %d", u);
    inOrder(T[u].right);
}
void postOrder(int u)
{
    if (u == NIL)
        return;
    postOrder(T[u].left);
    postOrder(T[u].right);
    printf(" %d", u);
}

void print(int n)
{
    int root;
    for (int i = 0; i < n; i++)
        if (T[i].parent == NIL)
            root = i;
    printf("Preorder\n");
    preOrder(root);
    printf("\n");
    printf("Inorder\n");
    inOrder(root);
    printf("\n");
    printf("Postorder\n");
    postOrder(root);
    printf("\n");
}

int main(void)
{
    int n, i, v, l, r;
    while (1)
    {
        scanf("%d", &n);
        if (n >= 1 && n <= 25)
            break;
    }

    for (i = 0; i < n; i++)
    {
        T[i].parent = T[i].left = T[i].right = NIL;
        Pre[i] = In[i] = Post[i];
    }

    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d", &v, &l, &r);
        p[i] = v;
        T[v].left = l;
        T[v].right = r;
        if (l != NIL)
            T[l].parent = v;
        if (r != NIL)
            T[r].parent = v;
    }

    print(n);

    return 0;
}