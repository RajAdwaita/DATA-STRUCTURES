#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 25

char stack[MAX];
char stack1[MAX];
void push(int x);
int pop();
int isFull();
int isEmpty();
int top = -1;

void push(int x)
{
    if (isFull())
    {
        printf("Stack 1 Overflow\n");
        return;
    }
    else
    {
        stack[++top] = x;
    }
}

int pop()
{
    if (isEmpty())
    {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

int isFull()
{
    if (top == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{

    int one = 0;
    int zero = 0;
    char str[25];

    scanf("%s", str);
    int l = strlen(str);
    for (int i = 0; i < l; i++)
    {
        char temp = str[i];
        push(temp);
    }
    while (!isEmpty())
    {
        char num = pop();
        if (num == '1')
        {
            one++;
        }
        else if (num == '0')
        {
            zero++;
        }
    }

    if (one == zero)
    {
        printf("Yes, equal.\n");
    }
    else
    {
        printf("No, unequal.\n");
    }

    return 0;
}