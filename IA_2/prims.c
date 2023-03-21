#include <stdio.h>


// he number of vertices in the spanning tree would be the same as the number of vertices in the original graph.
// V` = V
// The number of edges in the spanning tree would be equal to the number of edges minus 1.
// E` = |V| - 1
// The spanning tree should not contain any cycle.





#include <stdlib.h>

int a, b, u, v, n, i, j, ne = 1;
int visited[10] = {0}, min, mincost = 0, cost[10][10];

void main()
{
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    visited[1] = 1;
    printf("\n");
    
    while (ne < n)
    {
        for (i = 1, min = 999; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (cost[i][j] < min)
                    if (visited[i] != 0)
                    {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }

        if (visited[u] == 0 || visited[v] == 0)
        {
            printf("\n Edge %d:(%d %d) cost:%d", ne++, a, b, min);
            mincost += min;
            visited[b] = 1;
        }
        cost[a][b] = cost[b][a] = 999;
    }

    printf("\n Minimun cost=%d\n", mincost);
}


// ALGORITHM : PRIMS(G(V,E))
// PURPOSE : To find minimum spanning tree
// I/P : A weighted connected graph
// O/p : TE set of tree edges in MST

/*
TE = {}  TV = {0}   start with vertex 0 and no edges

while(TE contains fewer than n-1 edges) do
   let (u,v) be a least cost edge such that u(-TV and v!(- TV

   if(no such edge) then
     break
   end if
   
   add v to TV
   add (u,v) to TE

end while

if(TE contians fewer than n-1 edges)
  print("No spanning tree")
end if

EOA

*/



//   visited[1] = 1;
//     printf("\n");
    
//     while (ne < n)
//     {
//         for (i = 1, min = 999; i <= n; i++)
//             for (j = 1; j <= n; j++)
//                 if (cost[i][j] < min)
//                     if (visited[i] != 0)
//                     {
//                         min = cost[i][j];
//                         a = u = i;
//                         b = v = j;
//                     }

//         if (visited[u] == 0 || visited[v] == 0)
//         {
//             printf("\n Edge %d:(%d %d) cost:%d", ne++, a, b, min);
//             mincost += min;
//             visited[b] = 1;
//         }
//         cost[a][b] = cost[b][a] = 999;
//     }

//     printf("\n Minimun cost=%d\n", mincost);
