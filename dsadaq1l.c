#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    struct node *lchild;
    int info;
    struct node *rchild;
};
struct node *root = NULL;

static bool flag = false;

struct node *getnode(int x);
struct node *insert(struct node *p, int lvalue, int rvalue);
void display(struct node *p, int level);
void preorder(struct node *p);
void inorder(struct node *p);
void postorder(struct node *p);
void levelOrder(struct node *p);
int height(struct node *p);
void search(struct node *p, int key);

#define MAX 10

struct node *queue[MAX];
int front = -1, rear = -1;
void insertQueue(struct node *item);
struct node *deleteQueue();
int queueEmpty();

int main()
{
    root = NULL;
    root = getnode(1);
    int ch;
    int key;
    int lv, rv;

    // root = getnode(8);
    // root->lchild = getnode(6);
    // root->rchild = getnode(9);
    // root->lchild->lchild = getnode(45);
    // root->lchild->rchild = getnode(14);
    // root->rchild->lchild = getnode(7);
    // root->rchild->rchild = getnode(19);
    // root->rchild->lchild->rchild = getnode(59);
    // root->lchild->lchild->lchild = getnode(47);
    // root->lchild->lchild->rchild = getnode(3);
    // root->lchild->rchild->rchild = getnode(33);
    // root->rchild->rchild->lchild = getnode(67);
    while (1)
    {
        printf("\n");
        printf("1.Display tree: \n");
        printf("2.Search for an element: \n");
        printf("55.insert: \n");

        /*printf("4.Delete a node: \n");*/
        printf("3.PreOrder traversal: \n");
        printf("4.InOrder Traversal: \n");
        printf("5.PostOrder Traversal: \n");
        printf("6.LevelOrder Traversal: \n");

        printf("7.Height of Tree: \n");

        printf("8.QUIT: \n");
        printf("Enter your choice: \n");
        scanf("%d", &ch);

        if (ch == 8)
            break;

        switch (ch)
        {
        case 1:
            display(root, 0);
            printf("\n\n");
            break;
        case 55:
            printf("Enter the two vals: ");
            scanf("%d %d", &lv, &rv);
            root = insert(root, lv, rv);
            break;

        case 2:
            printf("Enter The key to be searched: ");
            scanf("%d", &key);
            search(root, key);
            if (flag)
                printf("Element exists\n");
            else
                printf("Element does not exist\n");
            break;

        case 3:
            printf("Preorder : ");
            preorder(root);
            printf("\n\n");
            break;
        case 4:
            printf("Inorder : ");
            inorder(root);
            printf("\n\n");
            break;

        case 5:
            printf("Postorder : ");
            postorder(root);
            printf("\n\n");

            break;
        case 6:
            printf("Level order : ");
            levelOrder(root);
            printf("\n\n");
            break;
        case 7:
            printf("Height of tree is %d\n", height(root));
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
    p->lchild = p->rchild = NULL;
}

struct node *insert(struct node *p, int lvalue, int rvalue)
{
    if (lvalue != -1)
    {
        p->lchild = getnode(lvalue);
    }
    if (rvalue != -1)
    {
        p->rchild = getnode(rvalue);
    }

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

void preorder(struct node *p)
{
    if (p == NULL)
        return;
    printf("%d   ", p->info);
    preorder(p->lchild);
    preorder(p->rchild);
}

void inorder(struct node *p)
{
    if (p == NULL)
        return;
    inorder(p->lchild);
    printf("%d   ", p->info);
    inorder(p->rchild);
}

void postorder(struct node *p)
{
    if (p == NULL)
        return;
    postorder(p->lchild);
    postorder(p->rchild);
    printf("%d   ", p->info);
}

int height(struct node *p)
{
    int hL, rL;

    if (p == NULL)
    {
        return 0;
    }

    hL = height(p->lchild);
    rL = height(p->rchild);

    if (hL > rL)
        return 1 + hL;
    else
        return 1 + rL;
}

void levelOrder(struct node *p)
{
    if (p == NULL)
    {
        printf("Tree is empty:\n");
        return;
    }

    insertQueue(p);
    while (!queueEmpty())
    {
        p = deleteQueue();
        printf("%d   ", p->info);
        if (p->lchild != NULL)
            insertQueue(p->lchild);
        if (p->rchild != NULL)
            insertQueue(p->rchild);
    }
}

void insertQueue(struct node *item)
{
    if (rear == MAX - 1)
    {
        printf("Queue overflow: \n");
        return;
    }

    if (front == -1)
    {
        front = 0;
    }
    rear += 1;
    queue[rear] = item;
}

struct node *deleteQueue()
{
    struct node *item;
    if (front == -1 || front == rear + 1)
    {
        printf("Queue Underflow:\n");
        return 0;
    }

    item = queue[front];
    front += 1;
    return item;
}

int queueEmpty()
{
    if (front == -1 || front == rear + 1)
        return 1;
    else
        return 0;
}

void search(struct node *p, int key)
{
    if (root == NULL)
    {
        printf("Tree is Empty\n");
    }
    else
    {
        if (p->info == key)
        {
            flag = true;
            return;
        }
        if (flag == false && p->lchild != NULL)
        {
            search(p->lchild, key);
        }
        if (flag == false && p->rchild != NULL)
        {
            search(p->rchild, key);
        }
    }
}