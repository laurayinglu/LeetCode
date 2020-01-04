#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    node *next;
} NODE;

inline int read()
{
    int f = 1, p = 0;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        p = p * 10 + c - '0';
        c = getchar();
    }
    return f * p;
}

void print(NODE *head, NODE *tail)
{
    NODE *p = head->next;
    while (p->next != NULL)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("%d\n", p->data);
}

void create(NODE *head, NODE *tail)
{
    int a;
    while ((a = read()) != 0)
    {
        NODE *newknot = (NODE *)malloc(sizeof(NODE));
        newknot->data = a;
        tail->next = newknot;
        newknot->next = NULL;
        tail = newknot;
    }
}

NODE *find(int search, NODE *head, NODE *tail)
{
    NODE *p = head->next;
    while (p->next != NULL)
    {
        if (p->data == search)
            return p;
        else
            p = p->next;
    }
    return p->data == search ? p : NULL;
}

void insert(NODE *head, NODE *tail)
{
    int pre = read();
    NODE *p = find(pre, head, tail);
    if (p != NULL)
    {
        int x = read();
        NODE *newknot = (NODE *)malloc(sizeof(NODE));
        newknot->data = x;
        newknot->next = p->next;
        p->next = newknot;
    }
}

void del(NODE *head, NODE *tail)
{
    int x = read();
    NODE *p = find(x, head, tail);
    if (p != NULL)
    {
        --p;
        p->next = p->next->next;
    }
}

int main()
{
    NODE *head = (NODE *)malloc(sizeof(NODE));
    NODE *tail = (NODE *)malloc(sizeof(NODE));
    head->next = tail;
    tail->next = NULL;
    tail = head;

    create(head, tail);
    print(head, tail);
    insert(head, tail);
    print(head, tail);
    del(head, tail);
    print(head, tail);




    return 0;
}
