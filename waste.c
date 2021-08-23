#include <stdio.h>
#include <stdlib.h>

struct node
{
    int regno;
    // char *name[25][25];
    int marks;
    struct node *next;
};

int main()
{

    struct node *head = (struct node *)malloc(10 * sizeof(struct node));

    head->regno = 234;
    // head->name = "a";
    head->marks = 9;
    head->next = NULL;

        return 0;
}