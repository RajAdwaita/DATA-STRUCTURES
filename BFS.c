#include <stdio.h>
#define MAX 10

void breadth_first_search(int adj[][MAX], int visited[], int start);

int n;

void breadth_first_search(int adj[][MAX], int visited[], int start)
{
    int queue[MAX], rear = -1, front = -1, i;
    queue[++rear] = start;
    visited[start] = 1;
    while (rear != front)
    {
        start = queue[++front];
        if (start == 11)
            printf("\t");
        else
            printf("%c \t", start + 65);
        for (i = 0; i < n; i++)
        {
            if (adj[start][i] == 1 && visited[i] == 0)
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}
int main()
{
    int visited[MAX] = {0};
    int adj[MAX][MAX], i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("\n Enter the adjacency matrix: ");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    printf("BFS:-\t");
    breadth_first_search(adj, visited, 0);
    return 0;
}