// #include <stdio.h>
// #include <stdlib.h>
// #define bool int

// struct sNode
// {
//     char data;
//     struct sNode *next;
// };

// void push(struct sNode **ref, int new_data);

// int pop(struct sNode **ref);

// bool isMatp(char char1, char char2)
// {
//     if (char1 == '(' && char2 == ')')
//         return 1;
//     else if (char1 == '{' && char2 == '}')
//         return 1;
//     else if (char1 == '[' && char2 == ']')
//         return 1;
//     else
//         return 0;
// }

// bool areBAL(char exp[])
// {
//     int i = 0;

//     struct sNode *stack = NULL;

//     while (exp[i])
//     {

//         if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
//             push(&stack, exp[i]);

//         if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
//         {

//             if (stack == NULL)
//                 return 0;

//             else if (!isMatp(pop(&stack), exp[i]))
//                 return 0;
//         }
//         i++;
//     }

//     if (stack == NULL)
//         return 1;
//     else
//         return 0;
// }

// int main()
// {
//     char exp[100];
//     gets(exp);

//     // Function call
//     if (areBAL(exp))
//         printf("Balanced \n");
//     else
//         printf("Not Balanced \n");
//     return 0;
// }

// void push(struct sNode **ref, int new_data)
// {

//     struct sNode *new_node = (struct sNode *)malloc(sizeof(struct sNode));

//     if (new_node == NULL)
//     {
//         printf("Stack overflow n");
//         getchar();
//         exit(0);
//     }

//     new_node->data = new_data;

//     new_node->next = (*ref);

//     (*ref) = new_node;
// }

// int pop(struct sNode **ref)
// {
//     char res;
//     struct sNode *top;

//     if (*ref == NULL)
//     {
//         printf("Stack overflow n");
//         getchar();
//         exit(0);
//     }
//     else
//     {
//         top = *ref;
//         res = top->data;
//         *ref = top->next;
//         free(top);
//         return res;
//     }
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

struct stack
{
    char stk[MAX];
    int top;
} s;

void push(char item)
{
    if (s.top == (MAX - 1))
        printf("Stack is Full\n");
    else
    {
        s.top = s.top + 1;
        s.stk[s.top] = item;
    }
}

void pop()
{
    if (s.top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        s.top = s.top - 1;
    }
}

int main()
{
    char exp[MAX];
    int i = 0;
    s.top = -1;
    printf("\nINPUT THE EXPRESSION : ");
    scanf("%s", exp);
    for (i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(exp[i]);
            continue;
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (exp[i] == ')')
            {
                if (s.stk[s.top] == '(')
                {
                    pop();
                }
                else
                {
                    printf("\nUNBALANCED EXPRESSION\n");
                    break;
                }
            }
            if (exp[i] == ']')
            {
                if (s.stk[s.top] == '[')
                {
                    pop();
                }
                else
                {
                    printf("\nUNBALANCED EXPRESSION\n");
                    break;
                }
            }
            if (exp[i] == '}')
            {
                if (s.stk[s.top] == '{')
                {
                    pop();
                }
                else
                {
                    printf("\nUNBALANCED EXPRESSION\n");
                    break;
                }
            }
        }
    }
    if (s.top == -1)
    {
        printf("\nBALANCED EXPRESSION\n");
    }
}
