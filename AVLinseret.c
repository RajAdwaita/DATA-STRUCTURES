#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};
struct node *new_node(int val);
struct node *insert(struct node *r, int val);
struct node *leftrotate(struct node *r);
struct node *rightrotate(struct node *r);
int getBalance(struct node *r);
int height(struct node *r);
int max(int a, int b);
void preorder(struct node *r);

struct node *new_node(int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;

    return temp;
}

struct node *leftrotate(struct node *r)
{
    struct node *a = r->right;
    struct node *y = a->left;

    a->left = r;
    r->right = y;

    a->height = 1 + max(height(a->left), height(a->right));
    r->height = 1 + max(height(a->left), height(a->right));

    return a;
}

struct node *rightrotate(struct node *r)
{
    struct node *a = r->left;
    struct node *y = a->right;

    a->right = r;
    r->left = y;

    a->height = 1 + max(height(a->left), height(a->right));
    r->height = 1 + max(height(a->left), height(a->right));

    return a;
}

int getBalance(struct node *r)
{
    if (r == NULL)
        return 0;

    return (height(r->left) - height(r->right));
}

int max(int a, int b)
{
    return ((a > b) ? a : b);
}

int height(struct node *r)
{
    if (r == NULL)
        return 0;
    return r->height;
}

void preorder(struct node *r)
{
    if (r == NULL)
        return;

    printf("%d  ", r->data);
    preorder(r->left);
    preorder(r->right);
}
struct node *insert(struct node *r, int val)
{
    if (r == NULL)
        return new_node(val);

    if (val < r->data)

        r->left = insert(r->left, val);

    else if (val > r->data)
        r->right = insert(r->right, val);

    else
    {
        return r;
    }

    r->height = 1 + max(height(r->left), height(r->right));

    int balance = getBalance(r);
    // LL
    if (balance > 1 && val < r->left->data)
    {
        return rightrotate(r);
    }

    //LR
    if (balance > 1 && val > r->left->data)
    {
        r->left = leftrotate(r->left);
        return rightrotate(r);
    }

    //RR

    if (balance < -1 && val > r->right->data)
    {
        return leftrotate(r);
    }

    //RL

    if (balance < -1 && val < r->right->data)
    {
        r->right = rightrotate(r->right);
        return leftrotate(r);
    }

    return r;
}
int main()
{
    // printf("Hello\n");

    struct node *root = NULL;

    root = insert(root, 12);
    root = insert(root, 65);
    root = insert(root, 45);
    root = insert(root, 23);
    root = insert(root, 11);
    root = insert(root, 67);
    root = insert(root, 98);
    // printf("%d\t", root->data);

    printf("Pre-order traversal is: ");
    preorder(root);
    printf("\n");

    return 0;
}