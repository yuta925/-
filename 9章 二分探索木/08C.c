#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int key;
    struct Node *left, *right, *parent;
} Node;

Node *root, *NIL;

Node *treeMinimum(Node *x)
{
    while (x->left != NIL)
        x = x->left;
    return x;
}

Node *treeSuccessor(Node *x)
{
    if (x->right != NIL)
        return treeMinimum(x->right);
    Node *y = x->parent;
    while (y != NIL && x == y->right)
    {
        x = y;
        y = y->right;
    }
    return y;
}

void insert(int key)
{
    Node *y = NIL;
    Node *x = root;
    Node *z;

    z = (Node *)malloc(sizeof(Node));
    z->key = key;
    z->left = NIL;
    z->right = NIL;

    while (x != NIL)
    {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;

    if (y == NIL)
        root = z;
    else
    {
        if (z->key < y->key)
            y->left = z;
        else
            y->right = z;
    }
}

Node *find(Node *u, int k)
{
    while (u != NIL && k != u->key)
    {
        if (k < u->key)
            u = u->left;
        else
            u = u->right;
    }
    return u;
}

void deleteNode(Node *z)
{
    Node *y;
    Node *x;

    if (z->left == NIL || z->right == NIL)
        y = z;
    else
        y = treeSuccessor(z);

    if (y->left != NIL)
        x = y->left;
    else
        x = y->right;

    if (x != NIL)
        x->parent = y->parent;

    if (y->parent == NIL)
        root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    if (y != z)
        z->key = y->key;

    free(y);
}

void inorder(Node *u)
{
    if (u == NIL)
        return;
    inorder(u->left);
    printf(" %d", u->key);
    inorder(u->right);
}

void preorder(Node *u)
{
    if (u == NIL)
        return;
    printf(" %d", u->key);
    preorder(u->left);
    preorder(u->right);
}

int main()
{
    int n, key;
    char com[20];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", com);
        if (strcmp(com, "insert") == 0)
        {
            scanf("%d", &key);
            insert(key);
        }
        else if (strcmp(com, "print") == 0)
        {
            inorder(root);
            printf("\n");
            preorder(root);
            printf("\n");
        }
        else if (strcmp(com, "find") == 0)
        {
            scanf("%d", &key);
            Node *res = find(root, key);
            if (res != NIL)
                printf("yes\n");
            else
                printf("no\n");
        }
        else if (strcmp(com, "delete") == 0)
        {
            scanf("%d", &key);
            deleteNode(find(root, key));
        }
    }

    return 0;
}
