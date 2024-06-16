#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int key;
    struct Node *next, *prev;
};

struct Node *nil;

struct Node *listSearch(int key)
{
    struct Node *cur = nil->next; // 番兵の次の要素から辿る
    while (cur != nil && cur->key != key)
    {
        cur = cur->next;
    }
    return cur;
}

void init()
{
    nil = (struct Node *)malloc(sizeof(struct Node));
    nil->next = nil;
    nil->prev = nil;
}

void printList()
{
    struct Node *cur = nil->next;
    int isf = 0;
    while (1)
    {
        if (cur == nil)
            break;
        if (isf++ > 0)
            printf(" ");
        printf("%d", cur->key);
        cur = cur->next;
    }
    printf("\n");
}

void deleteNode(struct Node *t)
{
    if (t == nil)
        return; // t が番兵の場合は処理しない
    t->prev->next = t->next;
    t->next->prev = t->prev;
    free(t);
}

void deleteFirst()
{
    deleteNode(nil->next);
}

void deleteLast()
{
    deleteNode(nil->prev);
}

void deleteKey(int key)
{
    // 検索したノードを削除
    deleteNode(listSearch(key));
}

void insert(int key)
{
    struct Node *x = (struct Node *)malloc(sizeof(struct Node));
    x->key = key;
    // 番兵の直後に要素を追加
    x->next = nil->next;
    nil->next->prev = x;
    nil->next = x;
    x->prev = nil;
}

int main(void)
{
    int key, n, i;
    char com[20];

    scanf("%d", &n);
    init();
    for (i = 0; i < n; i++)
    {
        scanf("%s %d", com, &key);
        if (com[0] == 'i')
        {
            insert(key);
        }
        else if (com[0] == 'd')
        {
            if (strlen(com) > 6)
            {
                if (com[6] == 'F')
                    deleteFirst();
                else if (com[6] == 'L')
                    deleteLast();
            }
            else
            {
                deleteKey(key);
            }
        }
    }

    printList();

    return 0;
}
