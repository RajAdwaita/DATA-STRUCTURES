#include <stdio.h>
#include <stdlib.h>
#define MAX 10
void DFS(int);
// void DFS(int i);

int adj[MAX][MAX], visited[MAX] = {0}, n;

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("\n Enter the adjacency matrix: ");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    printf("DFS Traversal: ");
    DFS(0);
    printf("\n");
    return 0;
}

void DFS(int i)
{
    int j;
    printf(" %c\t", i + 65);
    visited[i] = 1;

    for (int j = 0; j < n; j++)

        if (!visited[j] && adj[i][j] == 1)

            DFS(j);
}
