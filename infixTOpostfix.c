//only for single digit operands

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void infixTOpostfix(char infix[], char postfix[]);
long int evaluatePostfix(char postfix[]);
int precedence(char symbol);
int power(int b, int a);

long int stack[MAX];
int top = -1;
void push(long int symbol);
long int pop();
int isEmpty();
int isFull();

int main()
{
    char infix[MAX], postfix[MAX];
    printf("Enter infix Expression: ");
    gets(infix);

    infixTOpostfix(infix, postfix);
    printf("Postfix expression is : %s\n", postfix);
    printf("The Value of The Expression is: %ld\n", evaluatePostfix(postfix));

    return 0;
}

void infixTOpostfix(char infix[], char postfix[])
{
    unsigned int i, p;
    char next, symbol;

    p = 0;
    for (i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];

        if (symbol == ' ' || symbol == '\t')
        {
            continue;
        }
        switch (symbol)
        {
        case '(':
            push(symbol);
            break;
        case ')':
            while ((next = pop()) != '(')
                postfix[p++] = next;
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
            while (!isEmpty() && precedence(stack[top]) >= precedence(symbol))
                postfix[p++] = pop();
            push(symbol);
            break;
        default:
            postfix[p++] = symbol;
        }
    }
    while (!isEmpty())
    {
        postfix[p++] = pop();
    }
    postfix[p] = '\0';
}

int precedence(char symbol)
{
    switch (symbol)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;

    default:
        return 0;
    }
}

long int evaluatePostfix(char postfix[])
{
    long int x, y, result;
    unsigned int i;

    for (int i = 0; i < strlen(postfix); i++)
    {
        if (postfix[i] <= '9' && postfix[i] >= '0')
            push(postfix[i] - '0');
        else
        {
            x = pop();
            y = pop();

            switch (postfix[i])
            {
            case '+':
                push(y + x);
                break;
            case '-':
                push(y - x);
                break;
            case '*':
                push(y * x);
                break;
            case '/':
                push(y / x);
                break;
            case '%':
                push(y % x);
                break;
            case '^':
                push(power(y, x));
            }
        }
    }
    result = pop();
    return result;
}
int power(int b, int a)
{
    int i, x = 1;

    for (i = 1; i <= a; i++)
    {
        x *= b;
    }

    return x;
}

int isEmpty()
{
    if (top == -1)
        return 1;
    else
    {
        return 0;
    }
}

void push(long int symbol)
{
    if (isFull())
    {
        printf("Stack Overflow: \n");
        return;
    }
    top = top + 1;
    stack[top] = symbol;
}

int isFull()
{
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}

long int pop()
{
    int x;
    if (isEmpty())
    {
        printf("Stack Underflow: \n");
        exit(1);
    }
    x = stack[top];
    top = top - 1;
    return x;
}

// // For multi digit operands

// C program to evaluate value of a postfix
// // expression having multiple digit operands
// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>
// #include <stdlib.h>

// // Stack type
// struct Stack
// {
//     int top;
//     unsigned capacity;
//     int *array;
// };

// // Stack Operations
// struct Stack *createStack(unsigned capacity)
// {
//     struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));

//     if (!stack)
//         return NULL;

//     stack->top = -1;
//     stack->capacity = capacity;
//     stack->array = (int *)malloc(stack->capacity * sizeof(int));

//     if (!stack->array)
//         return NULL;

//     return stack;
// }

// int isEmpty(struct Stack *stack)
// {
//     return stack->top == -1;
// }

// int peek(struct Stack *stack)
// {
//     return stack->array[stack->top];
// }

// int pop(struct Stack *stack)
// {
//     if (!isEmpty(stack))
//         return stack->array[stack->top--];
//     return '$';
// }

// void push(struct Stack *stack, int op)
// {
//     stack->array[++stack->top] = op;
// }

// // The main function that returns value
// // of a given postfix expression
// int evaluatePostfix(char *exp)
// {
//     // Create a stack of capacity equal to expression size
//     struct Stack *stack = createStack(strlen(exp));
//     int i;

//     // See if stack was created successfully
//     if (!stack)
//         return -1;

//     // Scan all characters one by one
//     for (i = 0; exp[i]; ++i)
//     {
//         //if the character is blank space then continue
//         if (exp[i] == ' ')
//             continue;

//         // If the scanned character is an
//         // operand (number here),extract the full number
//         // Push it to the stack.
//         else if (isdigit(exp[i]))
//         {
//             int num = 0;

//             //extract full number
//             while (isdigit(exp[i]))
//             {
//                 num = num * 10 + (int)(exp[i] - '0');
//                 i++;
//             }
//             i--;

//             //push the element in the stack
//             push(stack, num);
//         }

//         // If the scanned character is an operator, pop two
//         // elements from stack apply the operator
//         else
//         {
//             int val1 = pop(stack);
//             int val2 = pop(stack);

//             switch (exp[i])
//             {
//             case '+':
//                 push(stack, val2 + val1);
//                 break;
//             case '-':
//                 push(stack, val2 - val1);
//                 break;
//             case '*':
//                 push(stack, val2 * val1);
//                 break;
//             case '/':
//                 push(stack, val2 / val1);
//                 break;
//             }
//         }
//     }
//     return pop(stack);
// }

// // Driver program to test above functions
// int main()
// {
//     char exp[50];
//     printf("Enter the expression: ");
//     gets(exp);
//     printf("%d", evaluatePostfix(exp));
//     return 0;
// }
