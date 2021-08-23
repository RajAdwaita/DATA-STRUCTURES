#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct node
{
    struct node *lchild;
    int info;
    struct node *rchild;
};

struct node *stack[MAX];
int top;
void initializeStack();
void push(struct node *item);
struct node *pop();
int empty();

struct node *getnode(int x);
struct node *insertNode(struct node *root, int x);
void inorder(struct node *ptr, int a[]);
struct node *Destroy(struct node *ptr);

int main()
{
    struct node *root = NULL;
    int a[MAX], n;

    printf("Enter number of Elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d ", i + 1);
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++)
        root = insertNode(root, a[i]);

    inorder(root, a);

    printf("\nSorted list is : \n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    root = Destroy(root);

    return 0;
}

struct node *getnode(int x)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));

    p->info = x;
    p->lchild = NULL;
    p->rchild = NULL;
    return p;
}

struct node *insertNode(struct node *root, int x)
{
    struct node *temp, *par, *p;

    p = root;
    par = NULL;

    while (p != NULL)
    {
        par = p;
        if (x < p->info)
            p = p->lchild;
        else
            p = p->rchild;
    }
    temp = getnode(x);

    if (par == NULL)
        root = temp;
    else if (x < par->info)
        par->lchild = temp;
    else
        par->rchild = temp;

    return root;
}

void inorder(struct node *root, int a[])
{
    struct node *p;
    int i;

    if (root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }

    initializeStack();
    p = root;
    i = 0;
    while (1)
    {
        while (p->lchild != NULL)
        {
            push(p);
            p = p->lchild;
        }

        while (p->rchild == NULL)
        {
            a[i++] = p->info;
            if (empty(133))
                return;
            p = pop();
        }

        a[i++] = p->info;
        p = p->rchild;
    }
    printf("\n");
}

struct node *Destroy(struct node *ptr)
{
    if (ptr != NULL)
    {
        Destroy(ptr->lchild);
        Destroy(ptr->rchild);
        free(ptr);
    }
    return NULL;
}

void initializeStack()
{
    top = -1;
}

void push(struct node *item)
{
    if (top == (MAX - 1))
    {
        printf("Stack Overflow\n");
        return;
    }

    stack[++top] = item;
}

struct node *pop()
{
    struct node *item;
    if (top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }

    item = stack[top--];
    return item;
}

int empty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}