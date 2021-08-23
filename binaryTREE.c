#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    struct node *lchild;
    char info;
    struct node *rchild;
};
struct node *root = NULL;
int count = 0;
static bool flag = false;
struct node *insert(struct node *p, char ele);
struct node *getnode(char x);
void display(struct node *p, int level);
void preorder(struct node *p);
void inorder(struct node *p);
void postorder(struct node *p);
void levelOrder(struct node *p);
int height(struct node *p);
void search(struct node *p, char key);
struct node *deleteNode(struct node *p, char x);
#define MAX 10

struct node *queue[MAX];
int front = -1, rear = -1;
void insertQueue(struct node *item);
struct node *deleteQueue();
int queueEmpty();

int main()
{
    root = NULL;
    int ch;
    char key;
    char nn;
    char el;

    while (1)
    {
        printf("\n");
        printf("1.Display tree: \n");
        printf("2.Insert element in tree: \n");

        printf("3.Search for an element: \n");
        printf("4.Delete a node: \n");
        printf("5.PreOrder traversal: \n");
        printf("6.InOrder Traversal: \n");
        printf("7.PostOrder Traversal: \n");
        printf("8.LevelOrder Traversal: \n");

        printf("9.Height of Tree: \n");

        printf("10.QUIT: \n");
        printf("Enter your choice: \n");
        scanf("%d", &ch);

        if (ch == 10)
            break;

        switch (ch)
        {
        case 1:
            display(root, 0);
            printf("\n\n");
            break;

        case 2:
            printf("Enter element to enter: \n");
            scanf("%c", &el);
            root = insert(root, el);
            break;

        case 3:
            printf("Enter The key to be searched: ");
            scanf("%c", &key);
            search(root, key);
            if (flag)
                printf("Element exists\n");
            else
                printf("Element does not exist\n");
            break;

        case 4:
            printf("Enter element to delete: ");
            scanf("%c", &nn);

            deleteNode(root, nn);
            break;

        case 5:
            printf("Preorder : ");
            preorder(root);
            printf("\n\n");
            break;
        case 6:
            printf("Inorder : ");
            inorder(root);
            printf("\n\n");
            break;

        case 7:
            printf("Postorder : ");
            postorder(root);
            printf("\n\n");

            break;
        case 8:
            printf("Level order : ");
            levelOrder(root);
            printf("\n\n");
            break;
        case 9:
            printf("Height of tree is %d\n", height(root));
            break;

        default:
            printf("Wrong Choice: \n");
            break;
        }
    }

    return 0;
}

struct node *insert(struct node *p, char ele)
{
    if (count == 0)
        p = getnode(ele);
    if (count == 1)
        p->lchild = getnode(ele);
    if (count == 2)
        p->rchild = getnode(ele);
    if (count == 3)
        p->lchild->lchild = getnode(ele);
    if (count == 4)
        p->lchild->rchild = getnode(ele);
    if (count == 5)
        p->rchild->lchild = getnode(ele);
    if (count == 6)
        p->rchild->rchild = getnode(ele);
    if (count == 7)
        p->rchild->lchild->rchild = getnode(ele);
    if (count == 8)
        p->lchild->lchild->lchild = getnode(ele);
    if (count == 9)
        p->lchild->lchild->rchild = getnode(ele);
    if (count == 10)
        p->lchild->rchild->rchild = getnode(ele);
    if (count == 11)
        p->rchild->rchild->lchild = getnode(ele);
    count++;
    return p;
}
struct node *getnode(char x)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->info = x;
    p->lchild = p->rchild = NULL;
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
    printf("%c", p->info);

    display(p->lchild, level + 1);
}

void preorder(struct node *p)
{
    if (p == NULL)
        return;
    printf("%c   ", p->info);
    preorder(p->lchild);
    preorder(p->rchild);
}

void inorder(struct node *p)
{
    if (p == NULL)
        return;
    inorder(p->lchild);
    printf("%c   ", p->info);
    inorder(p->rchild);
}

void postorder(struct node *p)
{
    if (p == NULL)
        return;
    postorder(p->lchild);
    postorder(p->rchild);
    printf("%c   ", p->info);
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
        printf("%c   ", p->info);
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

void search(struct node *p, char key)
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

struct node *deleteNode(struct node *p, char x)
{
    struct node *ch, *s;
    if(p==NULL)
        return;

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
    return p;
}
