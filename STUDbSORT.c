#include <stdio.h>
#include <stdlib.h>
#define MAX 25

typedef struct details
{
    char reg[25];
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

int size()
{
    return top + 1;
}

void display()
{

    int i;
    printf("Top =%d\n", top);
    if (isEmpty())
    {
        printf("stack is Empty : \n");
        return;
    }
    printf("Elements of the stack are:\n");

    for (i = top; i >= 0; i--)
    {
        printf("%d  ", stack[i]);
    }
    printf("\n");
}

int main()
{
    int n = 2;
    student students[n];
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter The Registration Number: ");
        fgets(students[i].reg, 20, stdin);
        printf("\nEnter The Name of The Student: ");
        fgets(students[i].name, 50, stdin);

        printf("\nEnter The School of The Student: ");
        fgets(students[i].school, 50, stdin);

        printf("\nEnter The Pcgpa of the Student: ");
        scanf("%f", &students[i].cg);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (students[j].cg < students[j + 1].cg)
            {
                student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    // student stud;
    int ch, x;
    while (1)
    {
        printf("1.Insert element in Stack:\n");
        printf("2.Delete element from Stack:\n");
        // printf("3.Display element in front:\n");
        printf("4.display all elements in Stack:\n");
        printf("5.display size of Stack :\n");
        printf("6.QUIT:\n");
        scanf("%d", &ch);

        if (ch == 6)
        {
            break;
        }
        switch (ch)
        {
        case 1:
        {
            printf("Enter element to insert:\n");
            scanf("%d", &x);
            push(x);
            break;
        }
        case 2:
        {
            x = pop();
            printf("Element deleted: %d\n\n", x);
            break;
        }
        // case 3:
        // {
        //     printf("Element at front is :%d\n\n", peek());

        //     break;
        // }
        case 4:
        {
            display();
            break;
        }
        case 5:
        {
            printf("size of Stack is :%d\n\n", size());

            break;
        }
        default:
        {
            printf("Wrong choice\n\n");
        }

            printf("\n");
        }
    }

    return 0;
}