
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *arr;
int top = -1;

void push(char ele)
{
    arr[++top] = ele;
}

char pop()
{
    return arr[top--];
}

int isPalin(char str[])
{
    int l = strlen(str);

    arr = (char *)malloc(l * sizeof(char));

    int i, mid = l / 2;

    for (i = 0; i < mid; i++)
    {
        push(str[i]);
    }

    if (l % 2 != 0)
    {
        i++;
    }

    while (str[i] != '\0')
    {
        char ele = pop();

        if (ele != str[i])
            return 0;
        i++;
    }
    free(arr);

    return 1;
}

int main()
{
    char str[50];
    // printf("Enter the word: ");
    gets(str);

    if (isPalin(str))
    {
        printf("PALINDROME\n");
    }
    else
    {
        printf("NOT PALINDROME");
    }

    return 0;
}
