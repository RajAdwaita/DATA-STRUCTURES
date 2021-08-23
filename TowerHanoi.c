#include <stdio.h>
#include <stdlib.h>
void tow_han(int, char, char, char);
int main()
{
    int n;
    scanf("%d", &n);

    tow_han(n, 'A', 'C', 'B');

    return 0;
}

void tow_han(int x, char to, char from, char aux)
{
    if (x == 1)
    {
        printf("Move disk %d from %c to %c \n", x, from, to);
        return;
    }
    tow_han(x - 1, from, aux, to);

    printf("Move disk %d from %c to %c \n", x, from, to);

    tow_han(x - 1, aux, to, from);
}