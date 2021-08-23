#include <stdio.h>
#include <stdlib.h>
#define MAX 25

typedef struct details
{
    int reg;
    char name[25];
    char school[25];
    float cg;
} student;

int stack[MAX];
int stack1[MAX];
void push(int x);
int pop();
int isFull();
int isEmpty();

void display();
int size();
int top = -1;

void push(int x)
{
    if (isFull())
    {
        printf("Stack Overflow\n");
        return;
    }
    else
    {
        stack[++top] = x;
    }
}

int pop()