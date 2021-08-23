#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *lchild;
    int info;
    struct node *rchild;
};

struct node *getnode(int x);
void display(struct node *p, int level);
struct node *search(struct node *p, int x);
struct node *insertNode(struct node *p, int x);
struct node *deleteNode(struct node *p, int x);
struct node *Min(struct node *p);
struct node *Max(struct node *p);
int height(struct node *p);
void preorder(struct node *p);
void inorder(struct node *p);
void postorder(struct node *p);

int main()
{
    struct node *root = NULL, *p;
    int ch, x;

    while (1)
    {
        printf("\n");
        printf("1.Display tree: \n");
        printf("2.Search for an element: \n");
        printf("3.Insert a new node:\n");
        printf("4.Delete a node: \n");
        printf("5.PreOrder traversal: \n");
        printf("6.InOrder Traversal: \n");
        printf("7.PostOrder Traversal: \n");
        printf("8.Height of Tree: \n");
        printf("9.Find Minimum key: \n");
        printf("10.Find Maximum key: \n");
        printf("11.QUIT: \n");
        printf("Enter your choice: \n");
        scanf("%d", &ch);

        if (ch == 11)
            break;

        switch (ch)
        {
        case 1:
            display(root, 0);
            break;

        case 2:
            printf("Enter The key to be searched: ");
            scanf("%d", &x);
            p = search(root, x);
            if (p == NULL)
                printf("Key not found:\n");
            else
                printf("Key Found\n");
            break;

        case 3:
            printf("Enter the key to be inserted: \n");
            scanf("%d", &x);
            root = insertNode(root, x);
            break;
        case 4:
            printf("Enter the key to be deleted: \n");
            scanf("%d", &x);
            root = deleteNode(root, x);
            break;

        case 5:
            printf("Pre-Order:-\n");
            preorder(root);
            break;
        case 6:
            printf("In-Order:-\n");
            inorder(root);
            break;
        case 7:
            printf("Post-Order:-\n");
            postorder(root);
            break;

        case 8:
            printf("Height of the tree is = %d\n", height(root));
            break;
        case 9:
            p = Min(root);
            if (p == NULL)
                printf("Tree is empty: \n");
            else
                printf("Minimum key is %d \n", p->info);
            break;

        case 10:
            p = Max(root);
            if (p == NULL)
                printf("Tree is empty: \n");
            else
                printf("Maximum key is %d \n", p->info);
            break;

        default:
            printf("Wrong Choice: \n");
            break;
        }
    }

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

void display(struct node *p, int level)
{
    if (p == NULL)
        return;
    display(p->rchild, level + 1);
    printf("\n");

    for (int i = 0; i < level; i++)
    {
        printf("     ");
    }
    printf("%d", p->info);

    display(p->lchild, level + 1);
}

struct node *insertNode(struct node *p, int x)
{
    if (p == NULL)
        p = getnode(x);
    else if (x < p->info)
        p->lchild = insertNode(p->lchild, x);
    else if (x > p->info)
        p->rchild = insertNode(p->rchild, x);
    else
        printf("%d already present in Tree: ", x);
    return p;
}

struct node *search(struct node *p, int x)
{
    if (p == NULL)
        return NULL;
    if (x < p->info)
        return search(p->lchild, x);
    if (x > p->info)
        return search(p->rchild, x);
    return p;
}

struct node *deleteNode(struct node *p, int x)
{
    struct node *ch, *s;

    if (p == NULL)
    {
        printf("%d not found \n", x);
        return p;
    }

    if (x < p->info)
        p->lchild = deleteNode(p->lchild, x);
    else if (x > p->info)
        p->rchild = deleteNode(p->rchild, x);
    else
    {
        if (p->lchild != NULL && p->rchild != NULL)
        {
            s = p->rchild;
            while (s->lchild)
                s = s->lchild;
            p->info = s->info;
            p->rchild = deleteNode(p->rchild, s->info);
        }

        else
        {
            if (p->lchild != NULL)
                ch = p->lchild;
            else
                ch = p->rchild;
            free(p);
            p = ch;
        }
    }
    return p;
}

struct node *Min(struct node *p)
{
    if (p == NULL)
        return NULL;
    while (p->lchild != NULL)
        p = p->lchild;
    return p;
}

struct node *Max(struct node *p)
{
    if (p == NULL)
        return NULL;
    while (p->rchild != NULL)
        p = p->rchild;
    return p;
}

int height(struct node *p)
{
    int l, r;

    if (p == NULL)
        return 0;
    l = height(p->lchild);
    r = height(p->rchild);

    if (l > r)
        return 1 + l;
    else
        return 1 + r;
}
void preorder(struct node *p)
{
    if (p == NULL)
        return;

    printf("%d ", p->info);
    preorder(p->lchild);
    preorder(p->rchild);
}
void inorder(struct node *p)
{
    if (p == NULL)
        return;

    inorder(p->lchild);
    printf("%d ", p->info);
    inorder(p->rchild);
}
void postorder(struct node *p)
{
    if (p == NULL)
        return;

    postorder(p->lchild);
    postorder(p->rchild);
    printf("%d ", p->info);
}
