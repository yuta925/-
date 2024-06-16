#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Node structure
struct Node
{
    int key;
    struct Node *parent, *left, *right;
};

// Declare root and NIL as pointers to Node
struct Node *root, *NIL;

// ノードを作成
struct Node *createNode(int key)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = NIL;
    newNode->right = NIL;
    newNode->parent = NIL;
    // 新しいノードの番地を返す
    return newNode;
}

// 新しいノードの挿入
void insert(int k)
{
    // yにNILの番地を代入
    struct Node *y = NIL;
    // xにrootの番地を代入
    struct Node *x = root;
    // zに新しいノードの番地を代入
    struct Node *z = createNode(k);

    // 初回はrootがNILなのでwhile文はスキップされる
    while (x != NIL)
    {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;
    // 初回はyがNILなのでrootにzを代入
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

// ノードの検索
void find(int k)
{
    struct Node *u = root;
    while (u != NIL && k != u->key)
    {
        if (k < u->key)
            u = u->left;
        else
            u = u->right;
    }
    if (u != NIL)
        printf("yes\n");
    else
        printf("no\n");
}

// 中間順巡回
void inorder(struct Node *u)
{
    if (u == NIL)
        return;
    inorder(u->left);
    printf(" %d", u->key);
    inorder(u->right);
}

// 先行順巡回
void preorder(struct Node *u)
{
    if (u == NIL)
        return;
    printf(" %d", u->key);
    preorder(u->left);
    preorder(u->right);
}

int main(void)
{
    int n, i, x;
    char com[10];

    // ダミーノードとしてNILを初期化
    NIL = (struct Node *)malloc(sizeof(struct Node));
    NIL->left = NIL->right = NIL->parent = NIL;

    // ルートをNILとして初期化
    root = NIL;

    // ノードの数を入力
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%s", com);
        if (strcmp(com, "insert") == 0)
        {
            scanf("%d", &x);
            insert(x);
        }
        else if (strcmp(com, "find") == 0)
        {
            scanf("%d", &x);
            find(x);
        }
        else if (strcmp(com, "print") == 0)
        {
            inorder(root);
            printf("\n");
            preorder(root);
            printf("\n");
        }
    }

    // NILノードを解放
    free(NIL);

    return 0;
}
