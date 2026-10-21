#include <stdio.h>

int a[10][10], visited[10], n;

void DFS(int v)
{
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++)
    {
        if (a[v][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

void BFS(int start)
{
    int q[10], front = 0, rear = 0;
    int vis[10] = {0};
    int v, i;

    q[rear++] = start;
    vis[start] = 1;

    while (front < rear)
    {
        v = q[front++];
        printf("%d ", v);

        for (i = 0; i < n; i++)
        {
            if (a[v][i] == 1 && vis[i] == 0)
            {
                q[rear++] = i;
                vis[i] = 1;
            }
        }
    }
}

int main()
{
    int e, u, v, i, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    for (i = 0; i < e; i++)
    {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        a[u][v] = 1;
        a[v][u] = 1;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    DFS(start);

    printf("\nBFS Traversal: ");
    BFS(start);

    return 0;
}