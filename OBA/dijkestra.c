// Dijkstra's Algorithm in C
//op https://docs.google.com/document/d/16X1IXpqgmnV1KVvM4Q3nXDlIMX9hCPmUHdWdtMF_1QA/edit?usp=sharing
#include <stdio.h>
#define INFINITY 9999
#define MAX 10

void dijkestra(int graph[MAX][MAX], int n, int start)
{
  int cost[MAX][MAX], distance[MAX], pred[MAX];
  int visited[MAX], count, mindistance, nextnode, i, j;

  // Creating cost matrix
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (graph[i][j] == 0)
        cost[i][j] = INFINITY;
      else
        cost[i][j] = graph[i][j];

  for (i = 0; i < n; i++)
  {
    distance[i] = cost[start][i];
    pred[i] = start;
    visited[i] = 0;
  }

  distance[start] = 0;
  visited[start] = 1;
  count = 1;

  while (count < n - 1)
  {
    mindistance = INFINITY;

    for (i = 0; i < n; i++)
      if (distance[i] < mindistance && !visited[i])
      {
        mindistance = distance[i];
        nextnode = i;
      }

    visited[nextnode] = 1;
    for (i = 0; i < n; i++)
      if (!visited[i])
        if (mindistance + cost[nextnode][i] < distance[i])
        {
          distance[i] = mindistance + cost[nextnode][i];
          pred[i] = nextnode;
        }
    count++;
  }

  // Printing the distance
  for (i = 0; i < n; i++)
    if (i != start)
    {
      printf("\nDistance from %d to %d is %d", start, i, distance[i]);
    }
}

int main()
{
  int a[10][10], n, start;
  printf("Enter the number of nodes : ");
  scanf("%d", &n);

  printf("Enter the cost matrix : \n");
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &a[i][j]);

  printf("Enter the start vertex : ");
  scanf("%d", &start);

  dijkestra(a, n, start);

  return 0;
}


/*  OUTPUT


Enter the number of nodes : 9
Enter the cost matrix : 
0 4 0 0 0 0 0 8 0 
4 0 8 0 0 0 0 11 0 
0 8 0 7 0 4 0 0 2 
0 0 7 0 9 14 0 0 0 
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0 
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7 
0 0 2 0 0 0 6 7 0 
Enter the start vertex : 0

Distance from 0 to 1 is 4
Distance from 0 to 2 is 12
Distance from 0 to 3 is 19
Distance from 0 to 4 is 21
Distance from 0 to 5 is 11
Distance from 0 to 6 is 9
Distance from 0 to 7 is 8
Distance from 0 to 8 is 14


*/
