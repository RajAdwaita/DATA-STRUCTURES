// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//     int data;
//     struct node *left;
//     struct node *right;
// };

// int search(int arr[], int strt, int end, int value);
// struct node *newNode(int data);

// struct node *buildTree(int in[], int pre[], int inStrt, int inEnd)
// {
//     static int preIndex = 0;

//     if (inStrt > inEnd)
//         return NULL;

//     struct node *tNode = newNode(pre[preIndex++]);

//     if (inStrt == inEnd)
//         return tNode;

//     int inIndex = search(in, inStrt, inEnd, tNode->data);

//     tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
//     tNode->right = buildTree(in, pre, inIndex + 1, inEnd);

//     return tNode;
// }

// int search(int arr[], int strt, int end, int value)
// {
//     int i;
//     for (i = strt; i <= end; i++)
//     {
//         if (arr[i] == value)
//             return i;
//     }
// }

// struct node *newNode(int data)
// {
//     struct node *node = (struct node *)malloc(sizeof(struct node));
//     node->data = data;
//     node->left = NULL;
//     node->right = NULL;

//     return (node);
// }

// void printInorder(struct node *node)
// {
//     if (node == NULL)
//         return;

//     printInorder(node->left);

//     printf("%d ", node->data);

//     printInorder(node->right);
// }

// int main()
// {
//     int in[7] = {11, 23, 25, 30, 31, 35, 42};
//     int pre[7] = {30, 23, 11, 25, 35, 31, 42};
//     int len = sizeof(in) / sizeof(in[0]);
//     struct node *root = buildTree(in, pre, 0, len - 1);

//     printf(" tree is \n");
//     printInorder(root);
// }

#include <stdio.h>
#include <stdlib.h>

int n;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}

struct node *constructTreeUtil(int pre[], int *preIndex,
                               int low, int high, int size)
{
    // Base case
    if (*preIndex >= size || low > high)
        return NULL;

    struct node *root = newNode(pre[*preIndex]);
    *preIndex = *preIndex + 1;

    if (low == high)
        return root;

    int i;
    for (i = low; i <= high; ++i)
        if (pre[i] > root->data)
            break;

    root->left = constructTreeUtil(pre, preIndex, *preIndex,
                                   i - 1, size);
    root->right = constructTreeUtil(pre, preIndex, i, high, size);

    return root;
}

struct node *constructTree(int pre[], int size)
{
    int preIndex = 0;
    return constructTreeUtil(pre, &preIndex, 0, size - 1,
                             size);
}

void printInorder(struct node *node)
{
    int k = 0;
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    // k++;s

    printInorder(node->right);
}

int main()
{
    int pre[7];
    int n;
    printf("Enter no of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pre[i]);
    }
    int size = sizeof(pre) / sizeof(pre[0]);

    struct node *root = constructTree(pre, size);

    printf("The constructed tree (inorder): \n");
    printInorder(root);

    return 0;
}
