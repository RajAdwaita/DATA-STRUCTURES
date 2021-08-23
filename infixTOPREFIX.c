
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define MAX 100

// void infixTOpostfix(char infix[], char postfix[]);
// long int evaluatePostfix(char postfix[]);
// int precedence(char symbol);
// int power(int b, int a);

// long int stack[MAX];
// int top = -1;
// void push(long int symbol);
// long int pop();
// int isEmpty();
// int isFull();

// int main()
// {
//     char infix1[MAX], postfix[MAX], infix[MAX];
//     printf("Enter infix Expression: ");
//     gets(infix1);
//     int k = 0;
//     char arr[strlen(infix1)];
//     for (int i = strlen(infix1) - 1; i > -1; i--)
//     {
//         if (infix1[i] == ')')
//         {
//             arr[k] = '(';
//         }

//         else if (infix1[i] == '(')
//         {
//             arr[k] = ')';
//         }
//         else
//         {
//             arr[k] = infix1[i];
//         }

//         k++;
//     }

//     infixTOpostfix(arr, postfix);
//     printf("Postfix expression is : %s\n", strrev(postfix));
//     printf("The Value of The Expression is: %ld\n", evaluatePostfix(postfix));

//     return 0;
// }

// void infixTOpostfix(char infix[], char postfix[])
// {
//     unsigned int i, p;
//     char next, symbol;

//     p = 0;
//     for (i = 0; i < strlen(infix); i++)
//     {
//         symbol = infix[i];

//         if (symbol == ' ' || symbol == '\t')
//         {
//             continue;
//         }
//         switch (symbol)
//         {
//         case '(':
//             push(symbol);
//             break;
//         case ')':
//             while ((next = pop()) != '(')
//                 postfix[p++] = next;
//             break;
//         case '+':
//         case '-':
//         case '*':
//         case '/':
//         case '%':
//         case '^':
//             while (!isEmpty() && precedence(stack[top]) >= precedence(symbol))
//                 postfix[p++] = pop();
//             push(symbol);
//             break;
//         default:
//             postfix[p++] = symbol;
//         }
//     }
//     while (!isEmpty())
//     {
//         postfix[p++] = pop();
//     }
//     postfix[p] = '\0';
// }

// int precedence(char symbol)
// {
//     switch (symbol)
//     {
//     case '(':
//         return 0;
//     case '+':
//     case '-':
//         return 1;
//     case '*':
//     case '/':
//     case '%':
//         return 2;
//     case '^':
//         return 3;

//     default:
//         return 0;
//     }
// }

// long int evaluatePostfix(char postfix[])
// {
//     long int x, y, result;
//     unsigned int i;

//     for (int i = 0; i < strlen(postfix); i++)
//     {
//         if (postfix[i] <= '9' && postfix[i] >= '0')
//             push(postfix[i] - '0');
//         else
//         {
//             x = pop();
//             y = pop();

//             switch (postfix[i])
//             {
//             case '+':
//                 push(y + x);
//                 break;
//             case '-':
//                 push(y - x);
//                 break;
//             case '*':
//                 push(y * x);
//                 break;
//             case '/':
//                 push(y / x);
//                 break;
//             case '%':
//                 push(y % x);
//                 break;
//             case '^':
//                 push(power(y, x));
//             }
//         }
//     }
//     result = pop();
//     return result;
// }
// int power(int b, int a)
// {
//     int i, x = 1;

//     for (i = 1; i <= a; i++)
//     {
//         x *= b;
//     }

//     return x;
// }

// int isEmpty()
// {
//     if (top == -1)
//         return 1;
//     else
//     {
//         return 0;
//     }
// }

// void push(long int symbol)
// {
//     if (isFull())
//     {
//         printf("Stack Overflow: \n");
//         return;
//     }
//     top = top + 1;
//     stack[top] = symbol;
// }

// int isFull()
// {
//     if (top == MAX - 1)
//         return 1;
//     else
//         return 0;
// }

// long int pop()
// {
//     int x;
//     if (isEmpty())
//     {
//         printf("Stack Underflow: \n");
//         exit(1);
//     }
//     x = stack[top];
//     top = top - 1;
//     return x;
// }

#include <stdio.h>
#include <string.h>
#define MAX 20
void infixtoprefix(char infix[20], char prefix[20]);
void reverse(char array[30]);
char pop();
void push(char symbol);
int isOperator(char symbol);
int prcd(symbol);
int top = -1;
char stack[MAX];
main()
{
    char infix[20], prefix[20], temp;
    printf("Enter infix operation: ");
    gets(infix);
    infixtoprefix(infix, prefix);
    reverse(prefix);
    puts((prefix));
}
//--------------------------------------------------------
void infixtoprefix(char infix[20], char prefix[20])
{
    int i, j = 0;
    char symbol;
    stack[++top] = '#';
    reverse(infix);
    for (i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];
        if (isOperator(symbol) == 0)
        {
            prefix[j] = symbol;
            j++;
        }
        else
        {
            if (symbol == ')')
            {
                push(symbol);
            }
            else if (symbol == '(')
            {
                while (stack[top] != ')')
                {
                    prefix[j] = pop();
                    j++;
                }
                pop();
            }
            else
            {
                if (prcd(stack[top]) <= prcd(symbol))
                {
                    push(symbol);
                }
                else
                {
                    while (prcd(stack[top]) >= prcd(symbol))
                    {
                        prefix[j] = pop();
                        j++;
                    }
                    push(symbol);
                }
                //end for else
            }
        }
        //end for else
    }
    //end for for
    while (stack[top] != '#')
    {
        prefix[j] = pop();
        j++;
    }
    prefix[j] = '\0';
}
////--------------------------------------------------------
void reverse(char array[30])
{ // for reverse of the given expression {
    int i;
    int j;
    char temp[100];
    for (i = strlen(array) - 1, j = 0; i + 1 != 0; --i, ++j)
    {
        temp[j] = array[i];
    }
    temp[j] = '\0';
    strcpy(array, temp);
    return array;
}
//--------------------------------
char pop()
{
    char a;
    a = stack[top];
    top--;
    return a;
}
//----------------------------------
void push(char symbol)
{
    top++;
    stack[top] = symbol;
}
//------------------------------------------
int prcd(symbol)
{ // returns the value that helps in the precedence {
    switch (symbol)
    {
    case '+':
    case '-':
        return 2;
        break;
    case '*':
    case '/':
        return 4;
        break;
    case '$':
    case '^':
        return 6;
        break;
    case '#':
    case '(':
    case ')':
        return 1;
        break;
    }
}
//-------------------------------------------------
int isOperator(char symbol)
{
    switch (symbol)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
    case '$':
    case '&':
    case '(':
    case ')':
        return 1;
        break;
    default:
        return 0;
        // returns 0 if the symbol is other than given above
    }
}