#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[10][10], n, ne = 1, u, v, i, j, mincost = 0, visited[10] = {0};
    printf("Enter the number of vertice : ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix : \n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 0)
                a[i][j] = 999;
        }
    }

    visited[1] = 1;
    while (ne < n)
    {
        for (int i = 1, min = 999; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[i][j] < min)
                {
                    if (visited[i])
                    {
                        min = a[i][j];
                        u = i, v = j;
                    }
                }
            }

            if (!visited[u] || !visited[v])
            {
                printf("\n edge %d(%d, %d) cost %d", ne++, u, v, min);
                mincost += min;
                visited[v] = 1;
            }
            a[u][v] = a[v][u] = 999;
        }
    }

    printf("mincost %d", mincost);

    return 0;
}
